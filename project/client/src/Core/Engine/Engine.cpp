#include "Engine.h"
#include "Graphics/Graphics.h"

namespace zw
{

    void Engine::ClearCanvas()
    {
        _<Graphics>().ClearCanvas();
    }

    void Engine::Update()
    {
    }

    void Engine::Render()
    {
        // Draw a triangle from the 3 vertices
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void Engine::PresentCanvas()
    {
        _<Graphics>().PresentCanvas();
    }
}