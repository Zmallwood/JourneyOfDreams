//  Modified work, Copyright (C) 2024 Andreas Åkerberg

#include "Hash.h"

namespace JourneyOfDreams
{
    int Hash(const std::string &text)
    {
        unsigned long hash = 5381;
        for (size_t i = 0; i < text.size(); ++i)
            hash = 33 * hash + (unsigned char)text[i];
        return static_cast<int>(hash);
    }
}