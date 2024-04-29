#pragma once

namespace JourneyOfDreams
{
    class ClientProperties
    {
      public:
        /////////////////////////////////////////////////
        /// Return canvas size in pixels.
        ///
        /// \return Size of canvas in pixels.
        /////////////////////////////////////////////////
        Size CanvasSize() const;

        /////////////////////////////////////////////////
        /// Get default color used to clear the 
        /// screen at the beginning of each frame.
        ///
        /// \return Default clear color.
        /////////////////////////////////////////////////
        ColorF DefaultClearColor() const;

        /////////////////////////////////////////////////
        /// Get number of rows in the 2D grid in
        /// the world view.
        ///
        /// \return Number of rows in the grid.
        /////////////////////////////////////////////////
        int NumGridRows() const;

      private:
        Size m_canvasSize{ 1000, 600 };
        ColorF m_defaultClearColor{ 0.0f, 0.5f, 1.0f };
        int m_numGridRows = 11;
    };
}