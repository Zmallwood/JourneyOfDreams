#include "RegisterNetRequestScene.h"
#include "Core/Engine/GUICore/GUILabel.h"
#include "Core/Engine/GUICore/GUITextBox.h"
#include "Core/Engine/Net/NetClient.h"
#include "Core/Engine/ScenesCore/SceneManager.h"
#include "DefaultTheme/Scenes/Register/RegisterScene.h"

namespace zw
{
    RegisterNetRequestScene::RegisterNetRequestScene()
    {
        GUI()->AddWidget("RegisterAccountLabel",
                         std::make_shared<GUILabel>(PointF{ .x = 0.5f, .y = 0.5f }, "Registering account...",
                                                    GUIAlign::Center));
    }

    void RegisterNetRequestScene::OnEnter()
    {
        auto username = _<RegisterScene>().GUI()->GetWidget<GUITextBox>("UsernameTextBox")->GetText();
        auto password = _<RegisterScene>().GUI()->GetWidget<GUITextBox>("PasswordTextBox")->GetText();
        auto confirmPassword
            = _<RegisterScene>().GUI()->GetWidget<GUITextBox>("ConfirmPasswordTextBox")->GetText();

        SHA256 sha;

        sha.update(password);
        std::array<uint8_t, 32> digestPassword = sha.digest();

        std::cout << SHA256::toString(digestPassword) << std::endl;

        sha.update(confirmPassword);
        std::array<uint8_t, 32> digestConfirmPassword = sha.digest();

        std::cout << SHA256::toString(digestConfirmPassword) << std::endl;

        //_<NetClient>().Send({{"Username", username},{"Password", password}});
    }
}
