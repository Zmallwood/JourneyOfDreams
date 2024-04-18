#pragma once

namespace zw
{
    class IScene;

    class SceneManager
    {
      public:
        SceneManager();
        void UpdateCurrentScene();
        void RenderCurrentScene();

      private:
        std::map<int, IScene&> m_scenes;
        int m_currentScene{ 0 };
    };
}