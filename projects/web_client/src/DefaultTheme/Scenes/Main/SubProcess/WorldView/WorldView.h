#pragma once

namespace zw
{
    class Engine;

    class WorldView
    {
      public:
        WorldView(Engine& engine);
        void Update();

        void Render();

      private:
        std::shared_ptr<std::vector<std::vector<RID>>> m_ridsTiles;
        std::shared_ptr<std::vector<std::vector<RID>>> m_ridsObjects;
        RID m_ridPlayer;
        RID m_ridHoveredTile;
        Engine& m_engine;
    };
}
