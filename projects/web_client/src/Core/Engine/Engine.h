// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

namespace JourneyOfDreams {
    /////////////////////////////////////////////////
    /// Core engine
    /////////////////////////////////////////////////
    class Engine {
      public:
        /////////////////////////////////////////////////
        /// Randomization seed and touch essential systems.
        /////////////////////////////////////////////////
        Engine();

        /////////////////////////////////////////////////
        /// Resets cursor style and clear canvas.
        /////////////////////////////////////////////////
        void Reset();

        /////////////////////////////////////////////////
        /// Polls events.
        /////////////////////////////////////////////////
        void HandleInput();

        /////////////////////////////////////////////////
        /// Update current scene in SceneManager.
        /////////////////////////////////////////////////
        void Update();

        /////////////////////////////////////////////////
        /// Update NetClients network logic.
        /////////////////////////////////////////////////
        void UpdateNet();

        /////////////////////////////////////////////////
        /// Render current scene in SceneManager and cursor.
        /////////////////////////////////////////////////
        void Render();

        /////////////////////////////////////////////////
        /// Update post render in SceneManager.
        /////////////////////////////////////////////////
        void UpdatePostRender();

        /////////////////////////////////////////////////
        /// Presents canvas.
        /////////////////////////////////////////////////
        void PresentCanvas();
    };
}
