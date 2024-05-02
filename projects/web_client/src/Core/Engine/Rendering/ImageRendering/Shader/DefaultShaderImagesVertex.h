#pragma once

namespace JourneyOfDreams
{
    /////////////////////////////////////////////////
    /// Default vertex shader for the images rendering.
    /////////////////////////////////////////////////
    // inline static const GLchar *defaultShaderImagesVertex =
    //     R"(
    //     attribute vec4 position;

    //     attribute vec2 in_Position;
    //     attribute vec4 in_Color;
    //     attribute vec2 in_TexCoord;

    //     varying vec4 ex_Color;
    //     varying vec2 ex_TexCoord;
    //     varying vec2 ex_Pos;

    //     void main() {
    //         gl_Position = vec4(in_Position.x, in_Position.y, 0.0, 1.0);
    //         ex_Color = in_Color;
    //         ex_TexCoord = in_TexCoord;
    //         ex_Pos = in_Position;
    //     }
    // )";
    inline static const GLchar *defaultShaderImagesVertex
        = "#version 300 es\n"
          "layout (location = 0) in vec3 aPos;\n"
          "layout (location = 1) in vec4 in_Color;\n"
          "layout (location = 2) in vec2 in_TexCoord;\n"
          "out vec4 ex_Color;\n"
          "out vec2 ex_TexCoord;\n"
          "out vec2 ex_Pos;\n"
          "void main()\n"
          "{\n"
          "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
          "   ex_Color = in_Color;\n"
          "   ex_TexCoord = in_TexCoord;\n"
          "   ex_Pos = aPos.xy;\n"
          "}\0";
}