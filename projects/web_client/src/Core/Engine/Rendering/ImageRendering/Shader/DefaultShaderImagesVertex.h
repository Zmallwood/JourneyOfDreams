#pragma once

namespace JourneyOfDreams
{
    inline static const GLchar *defaultShaderImagesVertex =
        R"(
        attribute vec4 position;

        attribute vec2 in_Position;
        attribute vec4 in_Color;
        attribute vec2 in_TexCoord;

        varying vec4 ex_Color;
        varying vec2 ex_TexCoord;
        varying vec2 ex_Pos;

        void main() {
            gl_Position = vec4(in_Position.x, in_Position.y, 0.0, 1.0);
            ex_Color = in_Color;
            ex_TexCoord = in_TexCoord;
            ex_Pos = in_Position;
        }
    )";
}