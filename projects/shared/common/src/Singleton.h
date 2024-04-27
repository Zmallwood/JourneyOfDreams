#pragma once

namespace zw
{
    template <class T>
    auto &_()
    {
        // static std::shared_ptr<T> instance = std::make_shared<T>();
        // return *instance;
        static T instance;
        return instance;
    }
}