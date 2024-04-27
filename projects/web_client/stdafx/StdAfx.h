#pragma once

#define GL_GLEXT_PROTOTYPES 1

#include <iostream>
#include <memory>
#include <map>
#include <utility>
#include <set>
#include <filesystem>
#include <numeric>
#include <ranges>
#include <fstream>
#include <algorithm>
#include <vector>
#include <functional>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengles2.h>
#include <SDL2/SDL_ttf.h>

// #include <emscripten/websocket.h>
// #include <emscripten.h>

#include "Common/Aliases.h"
#include "Common/SDLDeleter.h"
#include "Common/Utilities.h"
#include "Common/Square.h"

#include "Core/Engine/CoreMath/TileGridCalculations.h"

#include "../../shared/matter/src/Size.h"
#include "../../shared/matter/src/ColorF.h"
#include "../../shared/matter/src/RectF.h"
#include "../../shared/matter/src/GLRectF.h"
#include "../../shared/matter/src/Vertex2F.h"
#include "../../shared/matter/src/PointF.h"
#include "../../shared/matter/src/SizeF.h"
#include "../../shared/matter/src/Colors.h"
#include "../../shared/matter/src/Point.h"

#include "../../shared/common/src/Hash.h"
#include "../../shared/common/src/Singleton.h"

#include "../external/SHA256/include/SHA256.h"
