#include "ClientProperties.h"

namespace JourneyOfDreams
{
    Size ClientProperties::CanvasSize() const
    { 
        //
        // Return canvas size in pixels.
        //
        return m_canvasSize;
    }

    ColorF ClientProperties::DefaultClearColor() const
    { 
        //
        // Return default canvas clear color.
        //
        return m_defaultClearColor;
    }

    int ClientProperties::NumGridRows() const
    { 
        //
        // Return number of grid rows.
        //
        return m_numGridRows;
    }
}