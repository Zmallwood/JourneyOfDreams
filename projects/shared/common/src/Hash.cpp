// Modified work, Copyright (c) 2024 Andreas Åkerberg

#include "Hash.h"

namespace journey_of_dreams
{
  int
  Hash(const std::string &text) {
    unsigned long hash = 5381;
    for (size_t i = 0; i < text.size(); ++i)
      hash = 33 * hash + (unsigned char)text[i];
    return static_cast<int>(hash);
  }
} // namespace journey_of_dreams