#include "ServerConnectScene.h"
#include "Core/Engine/GUICore/GUILabel.h"

namespace zw
{
    ServerConnectScene::ServerConnectScene()
    {
        GUI()->AddWidget("ServerConnectLabel",
                         std::make_shared<GUILabel>(PointF{ .x = 0.5f, .y = 0.5f }, "Connecting to server...",
                                                    GUIAlign::Center));
    }
}
