// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

// precompiled headers for web_client

#define GL_GLEXT_PROTOTYPES 1

#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <ranges>
#include <set>
#include <stdio.h>
#include <utility>

#define GLFW_INCLUDE_ES3
#include <GLFW/glfw3.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengles2.h>
#include <SDL_ttf.h>
#include <stb_image.h>

#include <emscripten.h>
#include <emscripten/websocket.h>

#include "Common/Aliases.h"
#include "Common/CustomDeleter.h"
#include "Common/Square.h"
#include "Common/Utilities.h"

#include "Core/Engine/CoreMath/TileGridCalculations.h"

#include "../../shared/matter/src/ColorF.h"
#include "../../shared/matter/src/Colors.h"
#include "../../shared/matter/src/GLRectF.h"
#include "../../shared/matter/src/Point.h"
#include "../../shared/matter/src/PointF.h"
#include "../../shared/matter/src/RectF.h"
#include "../../shared/matter/src/Size.h"
#include "../../shared/matter/src/SizeF.h"
#include "../../shared/matter/src/Vertex2F.h"

#include "../../shared/common/src/Hash.h"
#include "../../shared/common/src/Singleton.h"

#include "../external/SHA256/include/SHA256.h"
