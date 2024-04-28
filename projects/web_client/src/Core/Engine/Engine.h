#pragma once

namespace zw
{
    class ImageBank;
    class Graphics;

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

        auto Graphics()
        {
            return m_graphics;
        }

      private:
        std::shared_ptr<zw::ImageBank> m_imageBank;
        std::shared_ptr<zw::Graphics> m_graphics;
    };
}
