#include "SceneManager.h"
#include "DefaultTheme/Scenes/Login/LoginScene.h"
#include "DefaultTheme/Scenes/LoginRequest/LoginRequestScene.h"
#include "DefaultTheme/Scenes/Main/MainScene.h"
#include "DefaultTheme/Scenes/ServerConnect/ServerConnectScene.h"

namespace zw
{
    SceneManager::SceneManager()
    {
        m_scenes.insert({ Hash("LoginScene"), _<LoginScene>() });
        m_scenes.insert({ Hash("ServerConnectScene"), _<ServerConnectScene>() });
        m_scenes.insert({ Hash("LoginRequestScene"), _<LoginRequestScene>() });
        m_scenes.insert({ Hash("MainScene"), _<MainScene>() });

        m_currentScene = Hash("LoginScene");
    }

    void SceneManager::UpdateCurrentScene()
    {
        if (m_scenes.contains(m_currentScene))
            m_scenes.at(m_currentScene).Update();
    }

    void SceneManager::RenderCurrentScene()
    {
        if (m_scenes.contains(m_currentScene))
            m_scenes.at(m_currentScene).Render();
    }

    void SceneManager::UpdatePostRenderCurrentScene()
    {
        if (m_scenes.contains(m_currentScene))
            m_scenes.at(m_currentScene).UpdatePostRender();
    }

    void SceneManager::GoToScene(const std::string &sceneName)
    {
        m_currentScene = Hash(sceneName);
        if (m_scenes.contains(m_currentScene))
            m_scenes.at(m_currentScene).OnEnter();
    }
}
