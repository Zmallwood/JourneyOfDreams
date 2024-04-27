#include "MainScene.h"
#include "Core/WorldFileReading/WorldFileReader.h"
#include "SubProcess/EnsureGoodPlayerPosition.h"
#include "SubProcess/FPSCounter.h"
#include "SubProcess/WorldView/WorldView.h"
#include "SubProcess/UpdateKeyboardMovement.h"
#include "SubProcess/TileHoverer.h"

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
        UpdateKeyboardMovement();
        _<TileHoverer>().Update();
        _<WorldView>().Update();
        _<FPSCounter>().Update();
    }

    void MainScene::RenderDerived()
    {
        _<WorldView>().Render();
        _<FPSCounter>().Render();
    }
}