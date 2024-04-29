#pragma once

namespace JourneyOfDreams
{
    class WorldView
    {
      public:
        WorldView();
        void Update();

        void Render();

      private:
        std::shared_ptr<std::vector<std::vector<RID>>> m_ridsTiles;
        std::shared_ptr<std::vector<std::vector<RID>>> m_ridsObjects;
        RID m_ridPlayer;
        RID m_ridHoveredTile;
    };
}
