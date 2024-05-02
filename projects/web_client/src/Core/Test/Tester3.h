//  Copyright (C) 2024 Andreas Åkerberg

#pragma once

namespace JourneyOfDreams
{
    class Tester3
    {
      public:
        Tester3();
        void Render();
        void Stop();

      private:
        bool m_active{ true };
        RID m_ridImage{ 0 };
    };
}