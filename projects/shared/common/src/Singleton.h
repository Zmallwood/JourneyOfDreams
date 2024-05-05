//  Copyright (C) 2024 Andreas Åkerberg

#pragma once

namespace JourneyOfDreams {
    template <class T>
    auto &_() {
        static T instance;
        return instance;
    }
}