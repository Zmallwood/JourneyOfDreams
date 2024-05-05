// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

// test3 class declaration.

namespace journey_of_dreams
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
} // namespace journey_of_dreams