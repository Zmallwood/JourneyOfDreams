#pragma once

namespace zw
{
    const GLchar *vertexSource = "attribute vec4 position;    \n"
                                 "void main()                  \n"
                                 "{                            \n"
                                 "   gl_Position = vec4(position.xyz, 1.0);  \n"
                                 "}                            \n";
}