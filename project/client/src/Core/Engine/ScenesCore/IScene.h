#pragma once

namespace zw
{
    class IScene
    {
      public:
        void Update();
        void Render();
        virtual void UpdateDerived() = 0;
        virtual void RenderDerived() = 0;
    };
}