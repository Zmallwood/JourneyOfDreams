#include "WorldView.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"

namespace zw
{
    WorldView::WorldView() : m_ridsTiles(std::make_shared<std::vector<std::vector<RID>>>())
    {
        for (auto x = 0; x < 11; x++)
        {
            m_ridsTiles->push_back(std::vector<RID>());
            for (auto y = 0; y < 11; y++)
            {
                m_ridsTiles->at(x).push_back(_<ImageRenderer>().NewImage());
            }
        }
    }

    void WorldView::Update()
    {
    }

    void WorldView::Render()
    {
        auto tileSize = 0.05f;
        for (auto y = 0; y < 11; y++)
        {
            for (auto x = 0; x < 11; x++)
            {
                auto dest = RectF{ x * tileSize, y * tileSize, tileSize, tileSize };
                _<ImageRenderer>().DrawImage(m_ridsTiles->at(x).at(y), "GroundGrass", dest);
            }
        }
    }
}