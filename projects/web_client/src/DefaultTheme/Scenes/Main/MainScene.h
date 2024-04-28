#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

namespace zw
{
    class TileHoverer;

    class MainScene : public IScene
    {
      public:
        MainScene(zw::Engine &engine);

        void OnEnter() override;

        void UpdateDerived() override;

        void RenderDerived() override;

        auto TileHoverer()
        {
            return m_tileHoverer;
        }

      private:
        std::shared_ptr<zw::TileHoverer> m_tileHoverer;
    };
}
