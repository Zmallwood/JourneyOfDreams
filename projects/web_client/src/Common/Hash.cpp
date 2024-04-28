#include "Hash.h"

namespace zw
{
    int Hash(const std::string &text)
    {
        return 123;
        // unsigned long hash = 5381;
        // for (size_t i = 0; i < text.size(); ++i)
        //     hash = 33 * hash + (unsigned char)text[i];
        // return static_cast<int>(hash);
    }
}