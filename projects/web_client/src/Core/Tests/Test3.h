/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

// test3 class declaration.

namespace JourneyOfDreams
{
  class Test3 {
   public:
    Test3();
    void Render();
    void Stop();

   private:
    bool m_active{true};
    RID m_ridImage{0};
  };
}