#include "LoginRequestScene.h"
#include "Core/Engine/GUICore/GUILabel.h"
#include "Core/Engine/Net/Net.h"
#include "Core/Engine/ScenesCore/SceneManager.h"

namespace zw
{
    LoginRequestScene::LoginRequestScene()
    {
        GUI()->AddWidget("AttempLoginLabel",
                         std::make_shared<GUILabel>(PointF{ .x = 0.5f, .y = 0.5f }, "Attempting to login...",
                                                    GUIAlign::Center));
    }

    void LoginRequestScene::OnEnter()
    {
    }
}
