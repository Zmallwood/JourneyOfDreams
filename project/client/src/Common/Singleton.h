#pragma once

namespace zw
{
    template <class T>
    auto &_()
    {
        static T instance;
        return instance;
    }
}