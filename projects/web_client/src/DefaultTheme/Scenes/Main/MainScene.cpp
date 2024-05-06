/* Copyright (c) 2024 Andreas Åkerberg. */

#include "MainScene.h"
#include "Core/WorldFileReading/WorldFileReader.h"
#include "SubProcess/EnsureGoodPlayerPosition.h"
#include "SubProcess/FPSCounter.h"
#include "SubProcess/TileHoverer.h"
#include "SubProcess/UpdateClickMovement.h"
#include "SubProcess/UpdateKeyboardMovement.h"
#include "SubProcess/WorldView/WorldView.h"

// main_scene class implementation.

namespace JourneyOfDreams
{
  void MainScene::OnEnter() {
    _<WorldFileReader>().ReadWorldFile();
    EnsureGoodPlayerPosition();
    _<WorldView>();
  }

  void MainScene::UpdateDerived() {
    UpdateKeyboardMovement();
    UpdateClickMovement();
    _<TileHoverer>().Update();
    _<WorldView>().Update();
    _<FPSCounter>().Update();
  }

  void MainScene::RenderDerived() {
    _<WorldView>().Render();
    _<FPSCounter>().Render();
  }
}