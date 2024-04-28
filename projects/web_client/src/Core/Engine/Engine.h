#pragma once

namespace zw
{
    class ImageBank;

    class Engine
    {
      public:
        Engine();

        void Reset();

        void HandleInput();

        void Update();

        void UpdateNet();

        void Render();

        void UpdatePostRender();

        void PresentCanvas();

        auto ImageBank()
        {
            return m_imageBank;
        }

      private:
        std::shared_ptr<zw::ImageBank> m_imageBank;
    };
}
