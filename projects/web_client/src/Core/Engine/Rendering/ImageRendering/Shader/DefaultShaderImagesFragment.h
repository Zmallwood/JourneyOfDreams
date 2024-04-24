#pragma once

namespace zw
{
    inline static const GLchar *defaultShaderImagesFragment =
        R"(
        precision mediump float;

        varying vec4 ex_Color;
        varying vec2 ex_TexCoord;
        varying vec2 ex_Pos;

        uniform sampler2D TexUnit;
        uniform float noPixelEffect;

        void main() {
            gl_FragColor = texture2D(TexUnit, ex_TexCoord);
        }
    )";

}