/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* DefaultShaderImagesFragment definition. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Default fragment shader for the images rendering.
  /////////////////////////////////////////////////
  inline static const GLchar *defaultShaderImagesFragment =
      "#version 300 es\n"
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