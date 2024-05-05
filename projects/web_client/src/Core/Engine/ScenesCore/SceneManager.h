// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

namespace journey_of_dreams {
    class IScene;

    class SceneManager {
      public:
        SceneManager();

        void UpdateCurrentScene();

        void RenderCurrentScene();

        void UpdatePostRenderCurrentScene();

        void GoToScene(const std::string &sceneName);

      private:
        std::map<int, IScene &> m_scenes;
        int m_currentScene{ 0 };
    };
}
