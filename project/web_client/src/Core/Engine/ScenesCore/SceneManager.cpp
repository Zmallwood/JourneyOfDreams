#include "SceneManager.h"
#include "DefaultTheme/Scenes/Intro/IntroScene.h"
#include "DefaultTheme/Scenes/Main/MainScene.h"
#include "DefaultTheme/Scenes/MainMenu/MainMenuScene.h"

namespace zw
{
    SceneManager::SceneManager()
    {
        m_scenes.insert({ Hash("IntroScene"), _<IntroScene>() });
        m_scenes.insert({ Hash("MainMenuScene"), _<MainMenuScene>() });
        m_scenes.insert({ Hash("MainScene"), _<MainScene>() });

        m_currentScene = Hash("IntroScene");
    }

    void SceneManager::UpdateCurrentScene()
    {
        if (m_scenes.count(m_currentScene))
            m_scenes.at(m_currentScene).Update();
    }

    void SceneManager::RenderCurrentScene()
    {
        if (m_scenes.count(m_currentScene))
            m_scenes.at(m_currentScene).Render();
    }

    void SceneManager::GoToScene(const std::string &sceneName)
    {
        m_currentScene = Hash(sceneName);
    }
}