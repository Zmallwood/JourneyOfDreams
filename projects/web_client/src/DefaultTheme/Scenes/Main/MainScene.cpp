#include "MainScene.h"
#include "Core/WorldFileReading/WorldFileReader.h"
#include "SubProcess/EnsureGoodPlayerPosition.h"
#include "SubProcess/FPSCounter.h"
#include "SubProcess/WorldView/WorldView.h"

namespace zw
{
    void MainScene::OnEnter()
    {
        _<WorldFileReader>().ReadWorldFile();
        EnsureGoodPlayerPosition();
        _<WorldView>();
    }

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