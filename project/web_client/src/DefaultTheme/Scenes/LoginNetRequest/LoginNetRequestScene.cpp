#include "LoginNetRequestScene.h"
#include "Core/Engine/GUICore/GUILabel.h"
#include "Core/Engine/GUICore/GUITextBox.h"
#include "Core/Engine/Net/NetClient.h"
#include "Core/Engine/ScenesCore/SceneManager.h"
#include "DefaultTheme/Scenes/Login/LoginScene.h"

namespace zw
{
    LoginNetRequestScene::LoginNetRequestScene()
    {
        GUI()->AddWidget("AttempLoginLabel",
                         std::make_shared<GUILabel>(PointF{ .x = 0.5f, .y = 0.5f }, "Attempting to login...",
                                                    GUIAlign::Center));
    }

    void LoginNetRequestScene::OnEnter()
    {
        auto username = _<LoginScene>().GUI()->GetWidget<GUITextBox>("UsernameTextBox")->GetText();
        auto password = _<LoginScene>().GUI()->GetWidget<GUITextBox>("PasswordTextBox")->GetText();
        _<NetClient>().Send({{"Username", username},{"Password", password}});
        _<SceneManager>().GoToScene("MainScene");
    }
}
