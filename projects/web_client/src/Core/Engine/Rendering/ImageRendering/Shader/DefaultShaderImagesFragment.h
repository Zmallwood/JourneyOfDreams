#pragma once

namespace JourneyOfDreams
{
    /////////////////////////////////////////////////
    /// Default fragment shader for the images rendering.
    /////////////////////////////////////////////////
    // inline static const GLchar *defaultShaderImagesFragment =
    //     R"(
    //     precision mediump float;

    //     varying vec4 ex_Color;
    //     varying vec2 ex_TexCoord;
    //     varying vec2 ex_Pos;

    //     uniform sampler2D TexUnit;
    //     uniform float noPixelEffect;

    //     void main() {
    //         gl_FragColor = texture2D(TexUnit, ex_TexCoord);
    //     }
    // )";
    inline static const GLchar *defaultShaderImagesFragment
        = "#version 300 es\n"
          "precision mediump float;\n"
          "in vec4 ex_Color;\n"
          "in vec2 ex_TexCoord;\n"
          "in vec2 ex_Pos;\n"
          "out vec4 FragColor;\n"
          "uniform sampler2D TexUnit;\n"
          "void main() {\n"
          "    FragColor = texture(TexUnit, ex_TexCoord);\n"
          "}\0";

}