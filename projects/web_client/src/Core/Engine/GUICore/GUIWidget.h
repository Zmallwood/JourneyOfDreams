// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "GUIAlign.h"
#include "WidgetEntry.h"

namespace journey_of_dreams
{
  class GUI;

  /////////////////////////////////////////////////
  /// A widget for the GUI.
  /////////////////////////////////////////////////
  class GUIWidget : public std::enable_shared_from_this<GUIWidget> {
   public:
    /////////////////////////////////////////////////
    /// Default constructor, only used by the GUI
    /// class which becomes the root widget.
    /////////////////////////////////////////////////
    GUIWidget();

    /////////////////////////////////////////////////
    /// Calls the other constructor with area
    /// separated into position and size.
    ///
    /// \param area Area of the widget.
    /// \param alignment Alignment of the widget.
    /////////////////////////////////////////////////
    GUIWidget(RectF area, GUIAlign alignment = GUIAlign::TopLeft);

    /////////////////////////////////////////////////
    /// Initializes class members and allocates
    /// graphical resources.
    ///
    /// \param position Position of the widget.
    /// \param size Size of the widget.
    /// \param alignment Alignment of the widget.
    /////////////////////////////////////////////////
    GUIWidget(PointF position, SizeF size,
              GUIAlign alignment = GUIAlign::TopLeft);

    /////////////////////////////////////////////////
    /// Inserts widgets that are waiting to be inserted
    /// and calls all the child widgets to do the same.
    /////////////////////////////////////////////////
    void InsertWaitingWidgets();

    /////////////////////////////////////////////////
    /// Marks this widget for destruction and calls
    /// all the child widgets to do the same.
    /////////////////////////////////////////////////
    void Destroy();

    /////////////////////////////////////////////////
    /// Erases all child widgets that are marked for
    /// destruction.
    /////////////////////////////////////////////////
    void DestroyMarkedWidgets();

    /////////////////////////////////////////////////
    /// Brings this widget to the front of all
    /// the other child widgets of the parent.
    /////////////////////////////////////////////////
    void BringToFront();

    /////////////////////////////////////////////////
    /// Tells if the mouse is over this widget.
    ///
    /// \return True if the mouse is over this widget.
    /////////////////////////////////////////////////
    bool MouseOver();

    /////////////////////////////////////////////////
    /// This is where deriving classes should put
    /// the code for adding child widgets.
    /////////////////////////////////////////////////
    virtual void Initialize();

    /////////////////////////////////////////////////
    /// Updates the widget and all the child widgets
    /// if this widget is visible.
    /////////////////////////////////////////////////
    virtual void Update();

    /////////////////////////////////////////////////
    /// Renders the widget and all the child widgets
    /// if this widget is visible.
    /////////////////////////////////////////////////
    virtual void Render();

    /////////////////////////////////////////////////
    /// This is where deriving classes should put
    /// the code for updating the widget.
    /////////////////////////////////////////////////
    virtual void UpdateDerived();

    /////////////////////////////////////////////////
    /// This is where deriving classes should put
    /// the code for rendering the widget.
    /////////////////////////////////////////////////
    virtual void RenderDerived();

    /////////////////////////////////////////////////
    /// Get all the child widgets of this widget,
    /// including all the child widgets of the children
    /// recursively.
    ///
    /// \return A vector of all the child widgets.
    /////////////////////////////////////////////////
    std::vector<WidgetEntry> GetChildWidgetsRecursively();

    /////////////////////////////////////////////////
    /// Adds a child widget to this widget with a name ID.
    ///
    /// \param nameIdentifier Name identifier of the widget.
    /// \param childWidget The child widget to add.
    /// \return The child widget that was added.
    /////////////////////////////////////////////////
    std::shared_ptr<GUIWidget>
    AddWidget(const std::string &nameIdentifier,
              std::shared_ptr<GUIWidget> childWidget);

    /////////////////////////////////////////////////
    /// Adds a child widget to this widget without a name ID.
    ///
    /// \param childWidget The child widget to add.
    /// \return The child widget that was added.
    /////////////////////////////////////////////////
    std::shared_ptr<GUIWidget>
    AddWidget(std::shared_ptr<GUIWidget> childWidget);

    /////////////////////////////////////////////////
    /// Gets all the child widgets of this widget,
    /// not recursively.
    ///
    /// \return A vector of all the child widgets.
    /////////////////////////////////////////////////
    std::vector<WidgetEntry> &ChildWidgets();

    /////////////////////////////////////////////////
    /// Gets the parent widgets of this widget,
    /// except for the root GUI objects which doesnt
    /// have a parent widget.
    ///
    /// \return The parent widget, or nullptr if
    ///         this object is a GUI.
    /////////////////////////////////////////////////
    std::shared_ptr<GUIWidget> ParentWidget();

    /////////////////////////////////////////////////
    /// Sets the parent widget of this widget.
    ///
    /// \param parentWidget The parent widget.
    /////////////////////////////////////////////////
    void SetParentWidget(std::shared_ptr<GUIWidget> parentWidget);

    /////////////////////////////////////////////////
    /// Gets the aligntment of this widget.
    ///
    /// \return The alignment of this widget.
    /////////////////////////////////////////////////
    GUIAlign Alignment();

    /////////////////////////////////////////////////
    /// Sets the size of this widget.
    ///
    /// \param size The size of this widget.
    /////////////////////////////////////////////////
    void SetSize(SizeF size);

    /////////////////////////////////////////////////
    /// Gets the size of this widget.
    ///
    /// \return The size of this widget.
    /////////////////////////////////////////////////
    SizeF Size();

    /////////////////////////////////////////////////
    /// Gets the padding of this widget.
    ///
    /// \return The padding of this widget.
    /////////////////////////////////////////////////
    float Padding();

    /////////////////////////////////////////////////
    /// Tells if this widget are able to get focus.
    ///
    /// \return True if this widget are able to get focus.
    /////////////////////////////////////////////////
    bool Focusable();

    /////////////////////////////////////////////////
    /// Tells if this widget has been marked for
    /// destruction.
    ///
    /// \return True if this widget has been marked for
    ///         destruction.
    /////////////////////////////////////////////////
    bool MarkedForDestruction();

    /////////////////////////////////////////////////
    /// Sets the flag for if this widget should be
    /// drawn with a background.
    ///
    /// \param drawBackground Draw background flag.
    /////////////////////////////////////////////////
    void SetDrawBackground(bool drawBackground);

    /////////////////////////////////////////////////
    /// Sets the flag for if this widget should be
    /// drawn with borders.
    ///
    /// \param drawBorders Draw borders flag.
    /////////////////////////////////////////////////
    void SetDrawBorders(bool drawBorders);

   protected:
    /////////////////////////////////////////////////
    /// Get the final position of this widget after
    /// alignment has been applied.
    ///
    /// \return The final position of this widget.
    /////////////////////////////////////////////////
    PointF GetFinalPosition();

    /////////////////////////////////////////////////
    /// Get the final area of this widget after
    /// alignment has been applied.
    ///
    /// \return The final area of this widget.
    /////////////////////////////////////////////////
    RectF GetFinalArea();

    /////////////////////////////////////////////////
    /// Focuses this widget.
    /////////////////////////////////////////////////
    virtual void Focus();

    /////////////////////////////////////////////////
    /// Tells if this widget has focus.
    ///
    /// \return True if this widget has focus.
    /////////////////////////////////////////////////
    bool HasFocus();

    /////////////////////////////////////////////////
    /// Gets the absolute position of this widget
    /// without alignment applied.
    ///
    /// \return The absolute position of this widget
    ///         without alignment applied.
    /////////////////////////////////////////////////
    virtual PointF GetAlignedAbsolutePosition();

    /////////////////////////////////////////////////
    /// Gets the root parent GUI object.
    ///
    /// \return The root parent GUI object.
    /////////////////////////////////////////////////
    std::shared_ptr<GUI> GetParentGUI();

    /////////////////////////////////////////////////
    /// Gets the background image of this widget.
    ///
    /// \return The background image of this widget.
    /////////////////////////////////////////////////
    std::string BackgroundImage();

    /////////////////////////////////////////////////
    /// Sets the background image of this widget.
    ///
    /// \param backgroundImage The background image
    ///                        of this widget.
    /////////////////////////////////////////////////
    void SetBackgroundImage(const std::string &backgroundImage);

    /////////////////////////////////////////////////
    /// Sets the flag for if this widget should be
    /// be able to get focus.
    ///
    /// \param focusable Focusable flag.
    /////////////////////////////////////////////////
    void SetFocusable(bool focusable);

    /////////////////////////////////////////////////
    /// Sets the ticks value for when this widget
    /// got focus.
    ///
    /// \return The ticks value for when this widget
    /////////////////////////////////////////////////
    int TicksTimeGotFocus();

    /////////////////////////////////////////////////
    /// Sets the flag for if this widget is visible.
    ///
    /// \param visible Visible flag.
    /////////////////////////////////////////////////
    void SetVisible(bool visible);

    /////////////////////////////////////////////////
    /// Sets the padding of this widget.
    ///
    /// \param padding The padding of this widget.
    /////////////////////////////////////////////////
    void SetPadding(float padding);

   private:
    PointF GetAbsolutePosition();
    PointF m_position{0.0f, 0.0f};
    SizeF m_size{100.0f, 100.0f};
    std::string m_backgroundImage{"GUIDefaultBackground"};
    std::string m_borderVerticalImage{"GUIDefaultBorderVertical"};
    std::string m_borderHorizontalImage{"GUIDefaultBorderHorizontal"};
    std::string m_borderCornerTopLeftImage{"GUIDefaultBorderCornerTopLeft"};
    std::string m_borderCornerTopRightImage{"GUIDefaultBorderCornerTopRight"};
    std::string m_borderCornerBottomRightImage{
        "GUIDefaultBorderCornerBottomRight"};
    std::string m_borderCornerBottomLeftImage{
        "GUIDefaultBorderCornerBottomLeft"};
    RID m_ridBackgroundImage{};
    RID m_ridBorderLeft;
    RID m_ridBorderTop;
    RID m_ridBorderRight;
    RID m_ridBorderBottom;
    RID m_ridBorderCornerTopLeft;
    RID m_ridBorderCornerTopRight;
    RID m_ridBorderCornerBottomRight;
    RID m_ridBorderCornerBottomLeft;
    SizeF m_backgroundPatternSize{0.2f, 0.2f};
    GUIAlign m_alignment{GUIAlign::TopLeft};
    std::vector<WidgetEntry> m_childWidgets;
    std::shared_ptr<GUIWidget> m_parentWidget{};
    float m_padding{0.01f};
    float m_borderWidth{0.01f};
    bool m_drawBackground{true};
    bool m_drawBorders{true};
    bool m_focusable{false};
    int m_ticksTimeGotFocus{0};
    bool m_markedForDestruction{false};
    std::shared_ptr<std::vector<WidgetEntry>> m_widgetsToInsert{};
    bool m_visible{true};
    inline static int s_unnamedWidgetCounter{0};
  };
} // namespace journey_of_dreams
