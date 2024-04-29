#pragma once

namespace JourneyOfDreams
{
    class Object
    {
      public:
        Object(const std::string &objectTypeName);
        Object(int objectTypeHash);
        auto Type() const
        {
            return m_type;
        }

      private:
        int m_type{ 0 };
    };
}