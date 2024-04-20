#pragma once

#include "GUIWidget.h"

namespace zw
{
    class GUI : public GUIWidget
    {
      public:
        void Update() override;
        void Render() override;
        template <class T>
        std::shared_ptr<T> GetWidget(const std::string &nameIdentifier)
        { 
            return static_pointer_cast<T>(GetWidget(nameIdentifier, shared_from_this()));
        }

      private:
        std::shared_ptr<GUIWidget> GetWidget(const std::string &nameIdentifier,
                                             std::shared_ptr<GUIWidget> widget);
    };
}