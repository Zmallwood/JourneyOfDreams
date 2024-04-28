#pragma once

namespace zw
{
    class Engine;
    class IScene;

    class SceneManager
    {
      public:
        SceneManager(Engine& engine);

        void Init();

        void UpdateCurrentScene();

        void RenderCurrentScene();

        void UpdatePostRenderCurrentScene();

        void GoToScene(const std::string &sceneName);

        template <class T>
        T &GetScene(const std::string &sceneName)
        {
            return dynamic_cast<T &>(*m_scenes.at(Hash(sceneName)));
        }

      private:
        std::map<int, std::shared_ptr<IScene>> m_scenes;
        int m_currentScene{ 0 };
        Engine &m_engine;
    };
}
