//  Copyright (C) 2024 Andreas Åkerberg

#include "GUIWidget.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "GUI.h"

namespace JourneyOfDreams {
    GUIWidget::GUIWidget() : m_widgetsToInsert(std::make_shared<std::vector<WidgetEntry>>()) {
        /*
        ** Do nothing. */
    }
    GUIWidget::GUIWidget(RectF area, GUIAlign alignment)
        : GUIWidget(area.GetPosition(), area.GetSize(), alignment) {
        /*
        ** Do nothing. */
    }
    GUIWidget::GUIWidget(PointF position, SizeF size, GUIAlign alignment)
        : m_position(position), m_size(size), m_alignment(alignment),
          m_widgetsToInsert(std::make_shared<std::vector<WidgetEntry>>()) {
        /*
        ** Allocate graphics resources. */
        m_ridBackgroundImage = _<ImageRenderer>().NewImage();
        m_ridBorderLeft = _<ImageRenderer>().NewImage();
        m_ridBorderRight = _<ImageRenderer>().NewImage();
        m_ridBorderTop = _<ImageRenderer>().NewImage();
        m_ridBorderBottom = _<ImageRenderer>().NewImage();
        m_ridBorderCornerTopLeft = _<ImageRenderer>().NewImage();
        m_ridBorderCornerTopRight = _<ImageRenderer>().NewImage();
        m_ridBorderCornerBottomLeft = _<ImageRenderer>().NewImage();
        m_ridBorderCornerBottomRight = _<ImageRenderer>().NewImage();
    }
    void GUIWidget::InsertWaitingWidgets() {
        /*
        ** Add all widgets from the waiting-collection. */
        for (auto &entry : *m_widgetsToInsert) {
            m_childWidgets.push_back(entry);
        }
        /*
        ** Now that they all are added, we can clear the waiting-collection. */
        m_widgetsToInsert->clear();
        /*
        ** Repeat this recursively for all child widgets. */
        for (auto &entry : m_childWidgets) {
            entry.widget->InsertWaitingWidgets();
        }
    }
    void GUIWidget::Destroy() {
        /*
        ** Mark this widget for destruction, erasing it here immediately would disrupt current
        ** iteration through the widgets for updating/rendering. */
        m_markedForDestruction = true;
        /*
        ** Mark also all the child widgets recursively. */
        for (auto &entry : m_childWidgets) {
            entry.widget->Destroy();
        }
    }
    void GUIWidget::DestroyMarkedWidgets() {
        /*
        ** Iterate through all child widgets. */
        for (auto it = ChildWidgets().begin(); it != ChildWidgets().end();) {
            /*
            ** First, destroy marked child widgets (recursively) of the child widget in iterator.
            ** They cannot be destroyed afterwards. */
            it->widget->DestroyMarkedWidgets();
            /*
            ** Check if the widget in the iterator should be destroyed. */
            if (it->widget->MarkedForDestruction()) {
                /*
                ** Erase it from the vector and set the iterator to the next element. */
                it = ChildWidgets().erase(it);
            } else {
                /*
                ** The iterator was not marked for destruction, just continue to next element. */
                ++it;
            }
        }
    }
    bool GUIWidget::MouseOver() {
        auto mousePosition = GetMousePosition();
        auto finalArea = GetFinalArea();
        /*
        ** Return true if mouse position is within the area of the widget. */
        return mousePosition.x >= finalArea.x && mousePosition.x <= finalArea.x + finalArea.w
               && mousePosition.y >= finalArea.y && mousePosition.y <= finalArea.y + finalArea.h;
    }
    void GUIWidget::Initialize() {
        /*
        ** Do nothing. */
    }
    void GUIWidget::BringToFront() {
        /*
        ** If has no parent widget, this widget must be a GUI and
        ** cannot be brought to front. */
        if (ParentWidget() == nullptr) {
            return;
        }
        /*
        ** Get the parents child widgets over which this widget should
        ** be place over. */
        auto &parentChildWidgets = ParentWidget()->ChildWidgets();
        /*
        ** Cancel if there are no other "competing" widgets. */
        if (parentChildWidgets.size() == 0) {
            return;
        }
        /*
        ** To hold the index of this widget, as it is stored in the parents
        ** child widget collection. */
        int i;

        for (i = 0; i < parentChildWidgets.size(); i++) {
            /*
            ** This widget, and its index, has been found so cancel the loop. */
            if (parentChildWidgets[i].widget.get() == this) {
                break;
            }
        }
        /*
        ** Get iterator of currently top-most widget.*/
        auto it = parentChildWidgets.begin() + i;
        /*
        ** Now swap this widget and the currently top-most widget. */
        std::rotate(it, it + 1, parentChildWidgets.end());
    }
    void GUIWidget::Update() {
        /*
        ** Dont update if not visible. */
        if (!m_visible) {
            return;
        }
        /*
        ** Update the child widgets before this one. (Recursively) */
        for (auto &entry : m_childWidgets) {
            entry.widget->Update();
        }
        /*
        ** Update the logic provided by inheriting classes. */
        UpdateDerived();
    }
    void GUIWidget::Render() {
        /*
        ** Dont render if not visible. */
        if (!m_visible) {
            return;
        }
        /*
        ** Get the position to which the widget will be rendered, if the default
        ** alignment of TopLeft is used. */
        auto alignedAbsPosition = GetAlignedAbsolutePosition();
        /*
        ** Combine the position with the widget size to get widget area. */
        auto finalArea = RectF{ alignedAbsPosition.x, alignedAbsPosition.y, m_size.w, m_size.h };

        if (m_drawBackground) {
            /*
            ** Calculate the fill values to get a repeating background image. */
            auto backgroundPatternFillAmount = SizeF{ .w = finalArea.w * m_backgroundPatternSize.w,
                                                      .h = finalArea.h * m_backgroundPatternSize.h };
            /*
            ** Adjust the final area according the alternative alignments. */
            switch (m_alignment) {
            case GUIAlign::TopLeft: {
                break;
            }
            case GUIAlign::TopCenter: {
                finalArea.x -= finalArea.w / 2;

                break;
            }
            case GUIAlign::TopRight: {
                finalArea.x -= finalArea.w;

                break;
            }
            case GUIAlign::RightCenter: {
                finalArea.x -= finalArea.w;
                finalArea.y -= finalArea.h / 2;

                break;
            }
            case GUIAlign::BottomRight: {
                finalArea.x -= finalArea.w;
                finalArea.y -= finalArea.h;

                break;
            }
            case GUIAlign::BottomCenter: {
                finalArea.x -= finalArea.w / 2;
                finalArea.y -= finalArea.h;

                break;
            }
            case GUIAlign::BottomLeft: {
                finalArea.y -= finalArea.h;

                break;
            }
            case GUIAlign::LeftCenter: {
                finalArea.y -= finalArea.h / 2;

                break;
            }
            case GUIAlign::Center: {
                finalArea.x -= finalArea.w / 2;
                finalArea.y -= finalArea.h / 2;

                break;
            }
            }
            /*
            ** Render the default widget background. */
            _<ImageRenderer>().DrawImage(m_ridBackgroundImage, m_backgroundImage, finalArea, true,
                                         backgroundPatternFillAmount);
        }

        if (m_drawBorders) {
            /*
            ** Get the width of the horizontal borders (top/bottom). */
            auto horizontalBorderWidth = m_borderWidth;
            /*
            ** Get the width of the vertical borders (left/right). */
            auto verticalBorderWidth = ConvertWidthToHeight(m_borderWidth);
            /*
            ** Determine pattern fill values to get a repeated image in the rendering. */
            auto borderHorizontalPatternFillAmount = SizeF{ 1.0f, finalArea.h * horizontalBorderWidth };
            auto borderVerticalPatternFillAmount = SizeF{ finalArea.w * verticalBorderWidth, 1.0f };
            /*
            ** Determine area of the left border and render it. */
            auto borderLeftalArea = RectF{ finalArea.x - horizontalBorderWidth, finalArea.y,
                                           horizontalBorderWidth, finalArea.h };
            _<ImageRenderer>().DrawImage(m_ridBorderLeft, m_borderVerticalImage, borderLeftalArea, true,
                                         borderHorizontalPatternFillAmount);
            /*
            ** Determine area of the left border and render it. */
            auto borderTopArea
                = RectF{ finalArea.x, finalArea.y - verticalBorderWidth, finalArea.w, verticalBorderWidth };
            _<ImageRenderer>().DrawImage(m_ridBorderTop, m_borderHorizontalImage, borderTopArea, true,
                                         borderVerticalPatternFillAmount);
            /*
            ** Determine area of the right border and render it. */
            auto borderRightArea
                = RectF{ finalArea.x + finalArea.w, finalArea.y, horizontalBorderWidth, finalArea.h };
            _<ImageRenderer>().DrawImage(m_ridBorderRight, m_borderVerticalImage, borderRightArea, true,
                                         borderHorizontalPatternFillAmount);
            /*
            ** Determine area of the bottom border and render it. */
            auto borderBottomArea
                = RectF{ finalArea.x, finalArea.y + finalArea.h, finalArea.w, verticalBorderWidth };
            _<ImageRenderer>().DrawImage(m_ridBorderBottom, m_borderHorizontalImage, borderBottomArea, true,
                                         borderVerticalPatternFillAmount);
            /*
            ** Determine area of the top left corner and render it. */
            auto borderCornerTopLeftArea
                = RectF{ finalArea.x - horizontalBorderWidth, finalArea.y - verticalBorderWidth,
                         horizontalBorderWidth, verticalBorderWidth };
            _<ImageRenderer>().DrawImage(m_ridBorderCornerTopLeft, m_borderCornerTopLeftImage,
                                         borderCornerTopLeftArea);
            /*
            ** Determine area of the top right corner and render it. */
            auto borderCornerTopRightArea
                = RectF{ finalArea.x + finalArea.w, finalArea.y - verticalBorderWidth, horizontalBorderWidth,
                         verticalBorderWidth };
            _<ImageRenderer>().DrawImage(m_ridBorderCornerTopRight, m_borderCornerTopRightImage,
                                         borderCornerTopRightArea);
            /*
            ** Determine area of the bottm right corner and render it. */
            auto borderCornerBottomRightArea = RectF{ finalArea.x + finalArea.w, finalArea.y + finalArea.h,
                                                      horizontalBorderWidth, verticalBorderWidth };
            _<ImageRenderer>().DrawImage(m_ridBorderCornerBottomRight, m_borderCornerBottomRightImage,
                                         borderCornerBottomRightArea);
            /*
            ** Determine area of the bottom left corner and render it. */
            auto borderCornerBottomLeftArea
                = RectF{ finalArea.x - horizontalBorderWidth, finalArea.y + finalArea.h,
                         horizontalBorderWidth, verticalBorderWidth };
            _<ImageRenderer>().DrawImage(m_ridBorderCornerBottomLeft, m_borderCornerBottomLeftImage,
                                         borderCornerBottomLeftArea);
        }
        /*
        ** Render all the child widgets on top of the already rendered background and borders. */
        for (auto &entry : m_childWidgets) {
            entry.widget->Render();
        }
        /*
        ** Render specific render operations in inherited classes. */
        RenderDerived();
    }
    void GUIWidget::UpdateDerived() {
        /*
        ** Do nothing. */
    }
    void GUIWidget::RenderDerived() {
        /*
        ** Do nothing. */
    }
    std::shared_ptr<GUIWidget> GUIWidget::AddWidget(const std::string &nameIdentifier,
                                                    std::shared_ptr<GUIWidget> childWidget) {
        auto nameHash = Hash(nameIdentifier);
        /*
        ** If widget with the provided widget name already exists, cancel. */
        for (auto &entry : m_childWidgets) {
            if (entry.id == nameHash) {
                return nullptr;
            }
        }
        /*
        ** If a widget with the provided widget name is already waiting to be inserted,
        ** cancel as well. */
        for (auto &entry : *m_widgetsToInsert) {
            if (entry.id == nameHash) {
                return nullptr;
            }
        }
        /*
        ** Initialize child widgets, such as adding its own child widgets. */
        childWidget->Initialize();
        /*
        ** Connect the widget to be added, by making this widget parent. */
        childWidget->SetParentWidget(shared_from_this());
        /*
        ** Add the widget to the collection where it will wait to be inserted. */
        m_widgetsToInsert->push_back({ nameHash, childWidget });
        /*
        ** Return the added child widgets, just for convenience. */
        return childWidget;
    }
    std::shared_ptr<GUIWidget> GUIWidget::AddWidget(std::shared_ptr<GUIWidget> childWidget) {
        /*
        ** "Nameless" widgets gets a autogenerated unique name under the hood. */
        auto generatedName = "Widget" + std::to_string(s_unnamedWidgetCounter++);
        /*
        ** Use the autogenerate image name to add the widget as usual. */
        return AddWidget(generatedName, childWidget);
    }
    PointF GUIWidget::GetAbsolutePosition() {
        /*
        ** Start with the position local from the parents point of view. */
        auto finalPosition = m_position;
        /*
        ** If parent exists (this is not a GUI), at the parents position to the local value.
        ** Note that this is done recursively. */
        if (m_parentWidget) {
            finalPosition += m_parentWidget->GetAbsolutePosition();
        }

        return finalPosition;
    }
    PointF GUIWidget::GetAlignedAbsolutePosition() {
        /*
        ** Start with the absolute position of this widget,
        ** assuming that the alignment is TopLeft. */
        auto alignedPosition = GetAbsolutePosition();
        /*
        ** If parent exists (this is not a GUI). */
        if (ParentWidget()) {
            /*
            ** Apply position translation depending on the
            ** alternative alignment types of the parent. */
            switch (ParentWidget()->Alignment()) {
            case GUIAlign::TopLeft: {
                break;
            }
            case GUIAlign::TopCenter: {
                alignedPosition.x -= ParentWidget()->Size().w / 2;

                break;
            }
            case GUIAlign::TopRight: {
                alignedPosition.x -= ParentWidget()->Size().w;

                break;
            }
            case GUIAlign::RightCenter: {
                alignedPosition.x -= ParentWidget()->Size().w;
                alignedPosition.y -= ParentWidget()->Size().h / 2;

                break;
            }
            case GUIAlign::BottomRight: {
                alignedPosition.x -= ParentWidget()->Size().w;
                alignedPosition.y -= ParentWidget()->Size().h;

                break;
            }
            case GUIAlign::BottomCenter: {
                alignedPosition.x -= ParentWidget()->Size().w / 2;
                alignedPosition.y -= ParentWidget()->Size().h;

                break;
            }
            case GUIAlign::BottomLeft: {
                alignedPosition.y -= ParentWidget()->Size().h;

                break;
            }
            case GUIAlign::LeftCenter: {
                alignedPosition.y -= ParentWidget()->Size().h / 2;

                break;
            }
            case GUIAlign::Center: {
                alignedPosition.x -= ParentWidget()->Size().w / 2;
                alignedPosition.y -= ParentWidget()->Size().h / 2;

                break;
            }
            }
        }
        /*
        ** Return this widgets position, having taken into account
        ** the parents alignment. */
        return alignedPosition;
    }
    PointF GUIWidget::GetFinalPosition() {
        /*
        ** Get the final positiong without padding. */
        auto paddedAlignedPosition = GetAlignedAbsolutePosition();
        /*
        ** Get horizontal and vertical padding value. */
        auto horizontalPadding = m_padding;
        auto verticalPadding = ConvertWidthToHeight(m_padding);
        /*
        ** Add padding according to this widgets alignment. */
        switch (m_alignment) {
        case GUIAlign::TopLeft: {
            paddedAlignedPosition.x += horizontalPadding;
            paddedAlignedPosition.y += verticalPadding;

            break;
        }
        case GUIAlign::TopCenter: {
            paddedAlignedPosition.x += -m_size.w / 2;
            paddedAlignedPosition.y += verticalPadding;

            break;
        }
        case GUIAlign::TopRight: {
            paddedAlignedPosition.x += -m_size.w - horizontalPadding;
            paddedAlignedPosition.y += verticalPadding;

            break;
        }
        case GUIAlign::RightCenter: {
            paddedAlignedPosition.x += -m_size.w - horizontalPadding;
            paddedAlignedPosition.y += -m_size.h / 2;

            break;
        }
        case GUIAlign::BottomRight: {
            paddedAlignedPosition.x += -m_size.w - horizontalPadding;
            paddedAlignedPosition.y += -m_size.h - verticalPadding;

            break;
        }
        case GUIAlign::BottomCenter: {
            paddedAlignedPosition.x += -m_size.w / 2;
            paddedAlignedPosition.y += -m_size.h - verticalPadding;

            break;
        }
        case GUIAlign::BottomLeft: {
            paddedAlignedPosition.x += horizontalPadding;
            paddedAlignedPosition.y += -m_size.h - verticalPadding;

            break;
        }
        case GUIAlign::LeftCenter: {
            paddedAlignedPosition.x += horizontalPadding;
            paddedAlignedPosition.y += m_size.h / 2;

            break;
        }
        case GUIAlign::Center: {
            break;
        }
        }

        return paddedAlignedPosition;
    }
    RectF GUIWidget::GetFinalArea() {
        auto finalPosition = GetFinalPosition();
        /*
        ** Combine final position and widget size to get final area. */
        return RectF{ finalPosition.x, finalPosition.y, m_size.w, m_size.h };
    }
    void GUIWidget::Focus() {
        /*
        ** Get root GUI object and set this widget as focused. */
        GetParentGUI()->SetFocusedWidget(shared_from_this());
        /*
        ** Store ticks value for when focus occured, used by the
        ** cursor blinking effect to reset at a new focus event. */
        m_ticksTimeGotFocus = Ticks();
    }
    std::shared_ptr<GUI> GUIWidget::GetParentGUI() {
        /*
        ** Start with current parent widget. */
        std::shared_ptr<GUIWidget> parent = m_parentWidget;
        /*
        ** Iterate "upwards" until there is no more parent widget. */
        while (parent->ParentWidget() != nullptr) {
            parent = parent->ParentWidget();
        }
        /*
        ** Cast the found root widget to GUI object. */
        return dynamic_pointer_cast<GUI>(parent);
    }
    bool GUIWidget::HasFocus() {
        /*
        ** Check if the widget has focus. */
        return GetParentGUI()->FocusedWidget() == shared_from_this();
    }
    std::vector<WidgetEntry> GUIWidget::GetChildWidgetsRecursively() {
        /*
        ** To hold all child widgets, and child widgets of child widgets
        ** and so on (recursively). */
        std::vector<WidgetEntry> result;
        /*
        ** Iterate through this widgets child widgets. */
        for (auto &entry : m_childWidgets) {
            /*
            ** Add the child widget. */
            result.push_back(entry);
            /*
            ** Call this same function but on the child widget, and get
            ** its results. */
            auto childResult = entry.widget->GetChildWidgetsRecursively();
            /*
            ** Add the child widget results to this function calls results. */
            result.insert(result.end(), childResult.begin(), childResult.end());
        }

        return result;
    }
    std::vector<WidgetEntry> &GUIWidget::ChildWidgets() {
        /*
        ** Getter by reference. */
        return m_childWidgets;
    }
    std::shared_ptr<GUIWidget> GUIWidget::ParentWidget() {
        /*
        ** Getter. */
        return m_parentWidget;
    }
    void GUIWidget::SetParentWidget(std::shared_ptr<GUIWidget> parentWidget) {
        /*
        ** Setter. */
        m_parentWidget = parentWidget;
    }
    GUIAlign GUIWidget::Alignment() {
        /*
        ** Getter. */
        return m_alignment;
    }
    void GUIWidget::SetSize(SizeF size) {
        /*
        ** Setter. */
        m_size = size;
    }
    SizeF GUIWidget::Size() {
        /*
        ** Getter. */
        return m_size;
    }
    float GUIWidget::Padding() {
        /*
        ** Getter. */
        return m_padding;
    }
    bool GUIWidget::Focusable() {
        /*
        ** Getter. */
        return m_focusable;
    }
    bool GUIWidget::MarkedForDestruction() {
        /*
        ** Getter. */
        return m_markedForDestruction;
    }
    void GUIWidget::SetDrawBackground(bool drawBackground) {
        /*
        ** Setter. */
        m_drawBackground = drawBackground;
    }
    void GUIWidget::SetDrawBorders(bool drawBorders) {
        /*
        ** Setter. */
        m_drawBorders = drawBorders;
    }
    std::string GUIWidget::BackgroundImage() {
        /*
        ** Getter. */
        return m_backgroundImage;
    }
    void GUIWidget::SetBackgroundImage(const std::string &backgroundImage) {
        /*
        ** Setter. */
        m_backgroundImage = backgroundImage;
    }
    void GUIWidget::SetFocusable(bool focusable) {
        /*
        ** Setter. */
        m_focusable = focusable;
    }
    int GUIWidget::TicksTimeGotFocus() {
        /*
        ** Setter. */
        return m_ticksTimeGotFocus;
    }
    void GUIWidget::SetVisible(bool visible) {
        /*
        ** Setter. */
        m_visible = visible;
    }
    void GUIWidget::SetPadding(float padding) {
        /*
        ** Setter. */
        m_padding = padding;
    }
}
