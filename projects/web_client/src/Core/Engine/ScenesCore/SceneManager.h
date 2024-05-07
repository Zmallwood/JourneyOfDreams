/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* SceneManager class declaration. */

namespace JourneyOfDreams
{
  class IScene;

  /////////////////////////////////////////////////
  /// Manages scenes and provides functionality for
  /// switching between them.
  /////////////////////////////////////////////////
  class SceneManager {
   public:
    /////////////////////////////////////////////////
    /// Initializes the game scenes.
    /////////////////////////////////////////////////
    SceneManager();

    /////////////////////////////////////////////////
    /// Updates the current scene inside the game loop.
    /////////////////////////////////////////////////
    void UpdateCurrentScene();

    /////////////////////////////////////////////////
    /// Renders the current scene inside the game loop.
    /////////////////////////////////////////////////
    void RenderCurrentScene();

    /////////////////////////////////////////////////
    /// Updates the current scene after rendering in
    /// the game loop.
    /////////////////////////////////////////////////
    void UpdatePostRenderCurrentScene();

    /////////////////////////////////////////////////
    /// Switches to the specified scene.
    ///
    /// @param sceneName The name of the scene to switch to.
    /////////////////////////////////////////////////
    void GoToScene(const std::string &sceneName);

   private:
    std::map<int, IScene &> m_scenes;
    int m_currentScene{0};
  };
}