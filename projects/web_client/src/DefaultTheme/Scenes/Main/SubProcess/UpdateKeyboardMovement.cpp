#include "UpdateKeyboardMovement.h"
#include "Core/Engine/CoreGameObjects/Player.h"
#include "Core/Engine/Input/KeyboardInput.h"

namespace zw
{
    void UpdateKeyboardMovement()
    {
        auto &player = _<Player>();
        auto upPressed = _<KeyboardInput>().KeyIsPressed(SDLK_UP);
        auto downPressed = _<KeyboardInput>().KeyIsPressed(SDLK_DOWN);
        auto leftPressed = _<KeyboardInput>().KeyIsPressed(SDLK_LEFT);
        auto rightPressed = _<KeyboardInput>().KeyIsPressed(SDLK_RIGHT);

        if (Ticks() > player.TicksLastMove() + 1000 / player.MovementSpeed()
            && (upPressed || rightPressed || downPressed || leftPressed))
        {
            if (upPressed)
            {
                player.MoveNorth();
            }
            if (rightPressed)
            {
                player.MoveEast();
            }
            if (downPressed)
            {
                player.MoveSouth();
            }
            if (leftPressed)
            {
                player.MoveWest();
            }
            player.SetTicksLastMove(Ticks());
        }
    }
}