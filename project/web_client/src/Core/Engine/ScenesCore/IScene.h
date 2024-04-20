#pragma once

#include "Core/Engine/GUICore/GUI.h"

namespace zw
{
    class IScene
    {
      public:
        IScene();
        void Update();
        void Render();
        virtual void UpdateDerived() = 0;
        virtual void RenderDerived() = 0;

      protected:
        auto GUI()
        {
            return m_gui;
        }

      private:
        std::shared_ptr<zw::GUI> m_gui;
    };
}