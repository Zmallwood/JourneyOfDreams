#include "Tester2.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"

namespace JourneyOfDreams
{
    Tester2::Tester2()
    {
        m_ridImage = _<ImageRenderer>().NewImage();
    }

    void Tester2::Render()
    {
        _<ImageRenderer>().DrawImage(m_ridImage, "DefaultSceneBackground", { 0.0f, 0.0f, 1.0f, 1.0f });
    }
}