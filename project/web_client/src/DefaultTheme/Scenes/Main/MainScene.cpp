#include "MainScene.h"
#include "SubProcess/FPSCounter.h"
#include "SubProcess/WorldView/WorldView.h"

namespace zw
{
    void MainScene::UpdateDerived()
    {
        _<WorldView>().Update();
        _<FPSCounter>().Update();
    }

    void MainScene::RenderDerived()
    {
        _<WorldView>().Render();
        _<FPSCounter>().Render();
    }
}