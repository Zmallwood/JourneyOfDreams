#pragma once

namespace zw
{
    class WorldView
    {
      public:
        WorldView();
        void Update();

        void Render();

      private:
        std::shared_ptr<std::vector<std::vector<RID>>> m_ridsTiles;
        RID m_ridPlayer;
    };
}
