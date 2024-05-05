// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

namespace journey_of_dreams
{
  class GUIWidget;

  /////////////////////////////////////////////////
  /// Storage-entry class for a widget in the GUI.
  /////////////////////////////////////////////////
  class WidgetEntry {
   public:
    /////////////////////////////////////////////////
    /// Id of the widget, equal to the hash of the
    /// widget name.
    /////////////////////////////////////////////////
    int id{0};

    /////////////////////////////////////////////////
    /// The widget.
    /////////////////////////////////////////////////
    std::shared_ptr<GUIWidget> widget{};
  };
} // namespace journey_of_dreams