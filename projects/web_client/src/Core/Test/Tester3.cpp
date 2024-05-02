//  Copyright (C) 2024 Andreas Åkerberg

#include "Tester3.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"

namespace JourneyOfDreams
{
    Tester3::Tester3()
    {
        m_ridImage = _<ImageRenderer>().NewImage();
    }

    void Tester3::Render()
    {
        if (!m_active)
        {
            return;
        }
        _<ImageRenderer>().DrawImage(m_ridImage, "DefaultSceneBackground", { 0.0f, 0.0f, 1.0f, 1.0f });
    }

    void Tester3::Stop()
    {
        m_active = false;
    }
}