#include "IScene.h"

namespace zw
{
    IScene::IScene() : m_gui(std::make_shared<GUI>())
    {
    }

    void IScene::Update()
    {
        UpdateDerived();
    }

    void IScene::Render()
    {
        RenderDerived();
    }
}