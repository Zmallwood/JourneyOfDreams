/* Copyright (c) 2024 Andreas Åkerberg. */

#include "IScene.h"
#include "Core/Engine/GUICore/GUI.h"

/* IScene class implementation. */

namespace JourneyOfDreams
{
  IScene::IScene()
      : m_gui(std::make_shared<JourneyOfDreams::GUI>()) {
    m_gui->Initialize();
  }

  void IScene::Update() {
    UpdateDerived();
    m_gui->Update();
  }

  void IScene::Render() {
    RenderDerived();
    m_gui->Render();
  }

  void IScene::OnEnter() {
  }

  void IScene::UpdateDerived() {
  }

  void IScene::RenderDerived() {
  }

  void IScene::UpdatePostRender() {
  }

  std::shared_ptr<JourneyOfDreams::GUI> IScene::GUI() {
    return m_gui;
  }
}