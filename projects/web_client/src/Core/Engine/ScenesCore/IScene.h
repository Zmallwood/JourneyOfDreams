// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

namespace journey_of_dreams
{
  class GUI;

  /////////////////////////////////////////////////
  /// Base class for all scenes in the game.
  /////////////////////////////////////////////////
  class IScene {
   public:
    /////////////////////////////////////////////////
    /// Initializes the scene GUI.
    /////////////////////////////////////////////////
    IScene();

    /////////////////////////////////////////////////
    /// Update the inheriting scene class and the scene GUI.
    /////////////////////////////////////////////////
    void Update();

    /////////////////////////////////////////////////
    /// Render the inheriting scene class and the scene GUI.
    /////////////////////////////////////////////////
    void Render();

    /////////////////////////////////////////////////
    /// Called when the scene is entered.
    /////////////////////////////////////////////////
    virtual void OnEnter();

    /////////////////////////////////////////////////
    /// Implemented by the inheriting scene class
    /// for doing specific game logic updates.
    /////////////////////////////////////////////////
    virtual void UpdateDerived();

    /////////////////////////////////////////////////
    /// Implemented by the inheriting scene class
    /// for rendering specific game graphics.
    /////////////////////////////////////////////////
    virtual void RenderDerived();

    /////////////////////////////////////////////////
    /// Called after the scene has been rendered.
    /////////////////////////////////////////////////
    virtual void UpdatePostRender();

    /////////////////////////////////////////////////
    /// Returns the scene GUI.
    ///
    /// \return The scene GUI.
    /////////////////////////////////////////////////
    std::shared_ptr<journey_of_dreams::GUI> GUI();

   private:
    std::shared_ptr<journey_of_dreams::GUI> m_gui;
  };
} // namespace journey_of_dreams
