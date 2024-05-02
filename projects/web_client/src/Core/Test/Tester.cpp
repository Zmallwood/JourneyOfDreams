#include "Tester.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"

namespace JourneyOfDreams
{
    Tester::Tester()
    {
        m_ridImage = _<ImageRenderer>().NewImage();
    }

    void Tester::Render()
    {
        _<ImageRenderer>().DrawImage(m_ridImage, "DefaultSceneBackground", { 0.0f, 0.0f, 1.0f, 1.0f });
    }
}