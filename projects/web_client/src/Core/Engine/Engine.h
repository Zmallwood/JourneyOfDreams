#pragma once

namespace zw
{
    class ImageBank;
    class Graphics;
    class NetClient;
    class SceneManager;
    class Cursor;
    class TextRenderer;

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

        auto NetClient()
        {
            return m_netClient;
        }

        auto SceneManager()
        {
            return m_sceneManager;
        }

        auto TextRenderer()
        {
            return m_textRenderer;
        }

      private:
        std::shared_ptr<zw::ImageBank> m_imageBank;
        std::shared_ptr<zw::Graphics> m_graphics;
        std::shared_ptr<zw::NetClient> m_netClient;
        std::shared_ptr<zw::SceneManager> m_sceneManager;
        std::shared_ptr<zw::Cursor> m_cursor;
        std::shared_ptr<zw::TextRenderer> m_textRenderer;
    };
}
