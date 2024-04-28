#pragma once

namespace zw
{
    class GUI;

    class IScene
    {
      public:
        IScene();

        void Update();

        void Render();

        virtual void OnEnter()
        {
        }

        virtual void UpdateDerived()
        {
        }

        virtual void RenderDerived()
        {
        }

        virtual void UpdatePostRender()
        {
        }

        auto GUI()
        {
            return m_gui;
        }

      private:
        std::shared_ptr<zw::GUI> m_gui;
    };
}
