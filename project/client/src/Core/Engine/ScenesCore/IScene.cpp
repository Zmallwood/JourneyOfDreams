#include "IScene.h"

namespace zw
{
    void IScene::Update()
    {
        UpdateDerived();
    }

    void IScene::Render()
    {
        RenderDerived();
    }
}