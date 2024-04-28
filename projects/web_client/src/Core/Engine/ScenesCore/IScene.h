#pragma once

namespace zw
{
    // class GUI;
    class Engine;

    class IScene
    {
      public:
        IScene(zw::Engine &engine);

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

      protected:
        auto& Engine()
        {
            return m_engine;
        }

        // auto GUI()
        // {
        //     return m_gui;
        // }

      private:
        // std::shared_ptr<zw::GUI> m_gui;
        zw::Engine &m_engine;
    };
}
