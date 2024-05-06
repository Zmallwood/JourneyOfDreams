/* Copyright (c) 2024 Andreas Åkerberg. */

#include "GUIWidget.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "GUI.h"

/* GUIWidget class implementation. */

namespace JourneyOfDreams
{
  GUIWidget::GUIWidget()
      : m_widgetsToInsert(std::make_shared<std::vector<WidgetEntry>>()) {
  }

  GUIWidget::GUIWidget(RectF area, GUIAlign alignment)
      : GUIWidget(area.GetPosition(), area.GetSize(), alignment) {
  }

  GUIWidget::GUIWidget(PointF position, SizeF size, GUIAlign alignment)
      : m_position(position),
        m_size(size),
        m_alignment(alignment),
        m_widgetsToInsert(std::make_shared<std::vector<WidgetEntry>>()) {
    /* Allocate graphics resources. */
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
    /* 1) Add all widgets from the waiting-collection.
     * 2) Now that they all are added, we can clear the waiting-collection.
     * 3) Repeat this recursively for all child widgets. */
    for (auto &entry : *m_widgetsToInsert) {
      m_childWidgets.push_back(entry);
    }
    m_widgetsToInsert->clear();
    for (auto &entry : m_childWidgets) {
      entry.widget->InsertWaitingWidgets();
    }
  }

  void GUIWidget::Destroy() {
    /* 1) Mark this widget for destruction, erasing it here immediately would
     *    disrupt current iteration through the widgets for updating/rendering.
     * 2) Mark also all the child widgets recursively. */
    m_markedForDestruction = true;
    for (auto &entry : m_childWidgets) {
      entry.widget->Destroy();
    }
  }

  void GUIWidget::DestroyMarkedWidgets() {
    /* 1) Iterate through all child widgets.
     * 2) First, destroy marked child widgets (recursively) of the child widget
     *    in iterator. They cannot be destroyed after the child widget has been
     *    destroyed.
     * 3) Check if the widget in the iterator is marked for destruction.
     * 4) If so, erase it from the vector and set the iterator to
     *    the next element.
     * 5) If the iterator is not marked for destruction, just continue to
     *    next element. */
    for (auto it = ChildWidgets().begin(); it != ChildWidgets().end();) {
      it->widget->DestroyMarkedWidgets();
      if (it->widget->MarkedForDestruction()) {
        it = ChildWidgets().erase(it);
      } else {
        ++it;
      }
    }
  }

  bool GUIWidget::MouseOver() {
    /* Return true if mouse position is within the area of the widget. */
    auto mousePosition = GetMousePosition();
    auto finalArea = GetFinalArea();
    return mousePosition.x >= finalArea.x &&
           mousePosition.x <= finalArea.x + finalArea.w &&
           mousePosition.y >= finalArea.y &&
           mousePosition.y <= finalArea.y + finalArea.h;
  }

  void GUIWidget::Initialize() {
  }

  void GUIWidget::BringToFront() {
    /* 1) If has no parent widget, this widget must be a GUI and
     *    cannot be brought to front.
     * 2) Get the parents child widgets over which this widget should
     *    be placed over.
     * 3) Cancel if there are no other "competing" widgets.
     * 4) Declare variable to hold the index of this widget, which it has
     *    in the parents child widget collection.
     * 5) If this widget, and its index, has been found, cancel the loop.
     * 6) Get iterator of currently top-most widget.
     * 7) Now swap this widget and the currently top-most widget. */
    if (ParentWidget() == nullptr) {
      return;
    }
    auto &parentChildWidgets = ParentWidget()->ChildWidgets();
    if (parentChildWidgets.size() == 0) {
      return;
    }
    int i;
    for (i = 0; i < parentChildWidgets.size(); i++) {
      if (parentChildWidgets[i].widget.get() == this) {
        break;
      }
    }
    auto it = parentChildWidgets.begin() + i;
    std::rotate(it, it + 1, parentChildWidgets.end());
  }

  void GUIWidget::Update() {
    /* 1) Dont update if not visible.
     * 2) Update the child widgets before this one. (Recursively)
     * 3) Update the logic provided by inheriting classes. */
    if (!m_visible) {
      return;
    }
    for (auto &entry : m_childWidgets) {
      entry.widget->Update();
    }
    UpdateDerived();
  }

  void GUIWidget::Render() {
    /* 1) Dont render if not visible.
     * 2) Get the position to which the widget will be rendered, if the default
     *    alignment of TopLeft is used.
     * 3) Combine the position with the widget size to get widget area. */
    if (!m_visible) {
      return;
    }
    auto alignedAbsPosition = GetAlignedAbsolutePosition();
    auto finalArea =
        RectF{alignedAbsPosition.x, alignedAbsPosition.y, m_size.w, m_size.h};
    if (m_drawBackground) {
      /* 1) Calculate the fill values to get a repeating background image.
       * 2) Adjust the final area according the alternative alignments.
       * 3) Render the default widget background. */
      auto backgroundPatternFillAmount =
          SizeF{.w = finalArea.w * m_backgroundPatternSize.w,
                .h = finalArea.h * m_backgroundPatternSize.h};
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
      _<ImageRenderer>().DrawImage(m_ridBackgroundImage, m_backgroundImage,
                                   finalArea, true,
                                   backgroundPatternFillAmount);
    }

    if (m_drawBorders) {
      /* 1) Get the width of the horizontal borders (top/bottom).
       * 2) Get the width of the vertical borders (left/right).
       * 3) Determine pattern fill values to get a repeated image in the
       *    rendering. */
      auto horizontalBorderWidth = m_borderWidth;
      auto verticalBorderWidth = ConvertWidthToHeight(m_borderWidth);
      auto borderHorizontalPatternFillAmount =
          SizeF{1.0f, finalArea.h * horizontalBorderWidth};
      auto borderVerticalPatternFillAmount =
          SizeF{finalArea.w * verticalBorderWidth, 1.0f};
      /* 1) Determine area of the left border and render it.
       * 2) Determine area of the top border and render it.
       * 3) Determine area of the right border and render it.
       * 4) Determine area of the bottom border and render it. */
      auto borderLeftalArea =
          RectF{finalArea.x - horizontalBorderWidth, finalArea.y,
                horizontalBorderWidth, finalArea.h};
      _<ImageRenderer>().DrawImage(m_ridBorderLeft, m_borderVerticalImage,
                                   borderLeftalArea, true,
                                   borderHorizontalPatternFillAmount);
      auto borderTopArea = RectF{finalArea.x, finalArea.y - verticalBorderWidth,
                                 finalArea.w, verticalBorderWidth};
      _<ImageRenderer>().DrawImage(m_ridBorderTop, m_borderHorizontalImage,
                                   borderTopArea, true,
                                   borderVerticalPatternFillAmount);
      auto borderRightArea = RectF{finalArea.x + finalArea.w, finalArea.y,
                                   horizontalBorderWidth, finalArea.h};
      _<ImageRenderer>().DrawImage(m_ridBorderRight, m_borderVerticalImage,
                                   borderRightArea, true,
                                   borderHorizontalPatternFillAmount);
      auto borderBottomArea = RectF{finalArea.x, finalArea.y + finalArea.h,
                                    finalArea.w, verticalBorderWidth};
      _<ImageRenderer>().DrawImage(m_ridBorderBottom, m_borderHorizontalImage,
                                   borderBottomArea, true,
                                   borderVerticalPatternFillAmount);
      /* 1) Determine area of the top left corner and render it.
       * 2) Determine area of the top right corner and render it.
       * 3) Determine area of the bottm right corner and render it.
       * 4) Determine area of the bottom left corner and render it. */
      auto borderCornerTopLeftArea =
          RectF{finalArea.x - horizontalBorderWidth,
                finalArea.y - verticalBorderWidth, horizontalBorderWidth,
                verticalBorderWidth};
      _<ImageRenderer>().DrawImage(m_ridBorderCornerTopLeft,
                                   m_borderCornerTopLeftImage,
                                   borderCornerTopLeftArea);
      auto borderCornerTopRightArea =
          RectF{finalArea.x + finalArea.w, finalArea.y - verticalBorderWidth,
                horizontalBorderWidth, verticalBorderWidth};
      _<ImageRenderer>().DrawImage(m_ridBorderCornerTopRight,
                                   m_borderCornerTopRightImage,
                                   borderCornerTopRightArea);
      auto borderCornerBottomRightArea =
          RectF{finalArea.x + finalArea.w, finalArea.y + finalArea.h,
                horizontalBorderWidth, verticalBorderWidth};
      _<ImageRenderer>().DrawImage(m_ridBorderCornerBottomRight,
                                   m_borderCornerBottomRightImage,
                                   borderCornerBottomRightArea);
      auto borderCornerBottomLeftArea =
          RectF{finalArea.x - horizontalBorderWidth, finalArea.y + finalArea.h,
                horizontalBorderWidth, verticalBorderWidth};
      _<ImageRenderer>().DrawImage(m_ridBorderCornerBottomLeft,
                                   m_borderCornerBottomLeftImage,
                                   borderCornerBottomLeftArea);
    }
    /* 1) Render all the child widgets on top of the already rendered background
     *    and borders
     * 2) Render specific render operations in inherited classes. */
    for (auto &entry : m_childWidgets) {
      entry.widget->Render();
    }
    RenderDerived();
  }

  void GUIWidget::UpdateDerived() {
  }

  void GUIWidget::RenderDerived() {
  }

  std::shared_ptr<GUIWidget>
  GUIWidget::AddWidget(const std::string &nameIdentifier,
                       std::shared_ptr<GUIWidget> childWidget) {
    /* 1) If widget with the provided widget name already exists, cancel.
     * 2) If a widget with the provided widget name is already waiting to be
     *    inserted, cancel as well.
     * 3) Initialize child widgets, such as adding its own child widgets.
     * 4) Connect the widget to be added, by making this widget parent.
     * 5) Add the widget to the collection where it will wait to be inserted.
     * 6) Return the added child widgets, just for convenience. */
    auto nameHash = Hash(nameIdentifier);
    for (auto &entry : m_childWidgets) {
      if (entry.id == nameHash) {
        return nullptr;
      }
    }
    for (auto &entry : *m_widgetsToInsert) {
      if (entry.id == nameHash) {
        return nullptr;
      }
    }
    childWidget->Initialize();
    childWidget->SetParentWidget(shared_from_this());
    m_widgetsToInsert->push_back({nameHash, childWidget});
    return childWidget;
  }

  std::shared_ptr<GUIWidget>
  GUIWidget::AddWidget(std::shared_ptr<GUIWidget> childWidget) {
    /* 1) "Nameless" widgets gets a autogenerated unique name under the hood.
     * 2) Use the autogenerate image name to add the widget as usual. */
    auto generatedName = "Widget" + std::to_string(s_unnamedWidgetCounter++);
    return AddWidget(generatedName, childWidget);
  }

  PointF GUIWidget::GetAbsolutePosition() {
    /* 1) Start with the position local from the parents point of view.
     * 2) If parent exists (this is not a GUI), at the parents position to the
     *    local value. Note that this is done recursively. */
    auto finalPosition = m_position;
    if (m_parentWidget) {
      finalPosition += m_parentWidget->GetAbsolutePosition();
    }
    return finalPosition;
  }

  PointF GUIWidget::GetAlignedAbsolutePosition() {
    /* 1) Start with the absolute position of this widget,
     *    assuming that the alignment is TopLeft.
     * 2) If parent exists (this is not a GUI),
     *    then apply position translation depending on the
     *    alternative alignment types of the parent.
     * 4) Return this widgets position, having taken into account
     *    the parents alignment. */
    auto alignedPosition = GetAbsolutePosition();
    if (ParentWidget()) {
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
    return alignedPosition;
  }

  PointF GUIWidget::GetFinalPosition() {
    /* 1) Get the final positiong without padding.
     * 2) Get horizontal and vertical padding value.
     * 3) Add padding according to this widgets alignment. */
    auto paddedAlignedPosition = GetAlignedAbsolutePosition();
    auto horizontalPadding = m_padding;
    auto verticalPadding = ConvertWidthToHeight(m_padding);
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
    /* Combine final position and widget size to get final area. */
    auto finalPosition = GetFinalPosition();
    return RectF{finalPosition.x, finalPosition.y, m_size.w, m_size.h};
  }

  void GUIWidget::Focus() {
    /* 1) Get root GUI object and set this widget as focused.
     * 2) Store ticks value for when focus occured, used by the
     *    cursor blinking effect to reset at a new focus event. */
    GetParentGUI()->SetFocusedWidget(shared_from_this());
    m_ticksTimeGotFocus = Ticks();
  }

  std::shared_ptr<GUI> GUIWidget::GetParentGUI() {
    /* 1) Start with current parent widget.
     * 2) Iterate "upwards" until there is no more parent widget.
     * 3) Cast the found root widget to a GUI object. */
    std::shared_ptr<GUIWidget> parent = m_parentWidget;
    while (parent->ParentWidget() != nullptr) {
      parent = parent->ParentWidget();
    }
    return dynamic_pointer_cast<GUI>(parent);
  }

  bool GUIWidget::HasFocus() {
    /* Check if the widget has focus. */
    return GetParentGUI()->FocusedWidget() == shared_from_this();
  }

  std::vector<WidgetEntry> GUIWidget::GetChildWidgetsRecursively() {
    /* 1) Declare variable to hold all child widgets, and child widgets of
     *    child widgets and so on (recursively).
     * 2) Iterate through this widgets child widgets.
     * 3) Add the child widget to results.
     * 4) Call this same function but on the child widget (recusive), and get
     *    its results.
     * 5) Add the child widget results to this function calls results. */
    std::vector<WidgetEntry> result;
    for (auto &entry : m_childWidgets) {
      result.push_back(entry);
      auto childResult = entry.widget->GetChildWidgetsRecursively();
      result.insert(result.end(), childResult.begin(), childResult.end());
    }
    return result;
  }

  std::vector<WidgetEntry> &GUIWidget::ChildWidgets() {
    return m_childWidgets;
  }

  std::shared_ptr<GUIWidget> GUIWidget::ParentWidget() {
    return m_parentWidget;
  }

  void GUIWidget::SetParentWidget(std::shared_ptr<GUIWidget> parentWidget) {
    m_parentWidget = parentWidget;
  }

  GUIAlign GUIWidget::Alignment() {
    return m_alignment;
  }

  void GUIWidget::SetSize(SizeF size) {
    m_size = size;
  }

  SizeF GUIWidget::Size() {
    return m_size;
  }

  float GUIWidget::Padding() {
    return m_padding;
  }

  bool GUIWidget::Focusable() {
    return m_focusable;
  }

  bool GUIWidget::MarkedForDestruction() {
    return m_markedForDestruction;
  }

  void GUIWidget::SetDrawBackground(bool drawBackground) {
    m_drawBackground = drawBackground;
  }

  void GUIWidget::SetDrawBorders(bool drawBorders) {
    m_drawBorders = drawBorders;
  }

  std::string GUIWidget::BackgroundImage() {
    return m_backgroundImage;
  }

  void GUIWidget::SetBackgroundImage(const std::string &backgroundImage) {
    m_backgroundImage = backgroundImage;
  }

  void GUIWidget::SetFocusable(bool focusable) {
    m_focusable = focusable;
  }

  int GUIWidget::TicksTimeGotFocus() {
    return m_ticksTimeGotFocus;
  }

  void GUIWidget::SetVisible(bool visible) {
    m_visible = visible;
  }

  void GUIWidget::SetPadding(float padding) {
    m_padding = padding;
  }
}