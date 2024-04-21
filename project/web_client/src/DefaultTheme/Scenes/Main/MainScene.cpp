#include "MainScene.h"
#include "SubProcess/FPSCounter.h"

namespace zw
{
    void MainScene::UpdateDerived()
    {
        _<FPSCounter>().Update();
    }

    void MainScene::RenderDerived()
    {
        _<FPSCounter>().Render();
    }
}