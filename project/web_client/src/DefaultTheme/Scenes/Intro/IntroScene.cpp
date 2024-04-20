#include "IntroScene.h"
#include "Core/Engine/Input/KeyboardInput.h"
#include "Core/Engine/Input/MouseInput.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"
#include "Core/Engine/ScenesCore/SceneManager.h"

namespace zw
{
    IntroScene::IntroScene()
    {
        m_ridBackground = _<ImageRenderer>().NewImage();
        m_ridLogo = _<ImageRenderer>().NewImage();
        m_startText = _<TextRenderer>().NewString();
    }

    void IntroScene::UpdateDerived()
    {
        if (_<KeyboardInput>().AnyKeyIsPressed() || _<MouseInput>().AnyButtonPressed())
            _<SceneManager>().GoToScene("MainMenuScene");
    }

    void IntroScene::RenderDerived()
    {
        _<ImageRenderer>().DrawImage(m_ridBackground, "DefaultSceneBackground", { 0.0f, 0.0f, 1.0f, 1.0f },
                                     { 1.0f, 1.0f, 1.0f, 1.0f });
        _<ImageRenderer>().DrawImage(m_ridLogo, "JourneyOfDreamsLogo", { 0.3f, 0.2f, 0.4f, 0.2f },
                                     { 1.0f, 1.0f, 1.0f, 1.0f });

        if (SDL_GetTicks() % 600 < 400)
        {
            _<TextRenderer>().DrawString(m_startText, "Press any key to start", { 0.5f, 0.6f },
                                         { 1.0f, 1.0f, 1.0f, 1.0f }, true, FontSizes::_20);
        }
    }
}