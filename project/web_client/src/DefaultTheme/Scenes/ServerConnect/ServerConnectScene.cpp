#include "ServerConnectScene.h"
#include "Core/Engine/GUICore/GUILabel.h"
#include "Core/Engine/Net/Net.h"
#include "Core/Engine/ScenesCore/SceneManager.h"

namespace zw
{
    ServerConnectScene::ServerConnectScene()
    {
        GUI()->AddWidget("ServerConnectLabel",
                         std::make_shared<GUILabel>(PointF{ .x = 0.5f, .y = 0.5f }, "Connecting to server...",
                                                    GUIAlign::Center));
    }

    void ServerConnectScene::OnEnter()
    {
        _<Net>().BeginEstablishConnection();
    }

    void ServerConnectScene::UpdateDerived()
    {
        if (_<Net>().Connected())
        {
            _<SceneManager>().GoToScene("LoginRequestScene");
        }
    }
}
