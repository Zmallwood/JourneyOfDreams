// Copyright (c) 2024 Andreas Åkerberg.

#include "Test3.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"

namespace journey_of_dreams
{
  Test3::Test3() {
    m_ridImage = _<ImageRenderer>().NewImage();
  }

  void
  Test3::Render() {
    if (!m_active) {
      return;
    }
    _<ImageRenderer>().DrawImage(m_ridImage, "DefaultSceneBackground",
                                 {0.0f, 0.0f, 1.0f, 1.0f});
  }
  
  void
  Test3::Stop() {
    m_active = false;
  }
} // namespace journey_of_dreams