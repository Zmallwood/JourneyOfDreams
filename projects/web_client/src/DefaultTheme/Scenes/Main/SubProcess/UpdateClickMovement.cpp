#include "UpdateClickMovement.h"
#include "Core/Engine/CoreGameObjects/Player.h"
#include "Core/Engine/Input/MouseInput.h"
#include "Core/Engine/Engine.h"
#include "Core/Engine/ScenesCore/SceneManager.h"
#include "DefaultTheme/Scenes/Main/MainScene.h"
#include "TileHoverer.h"

namespace zw
{
    void UpdateClickMovement(Engine& engine)
    {
        // auto &player = _<Player>();
        // auto hoveredCoord = engine.SceneManager()->GetScene<MainScene>("MainScene").TileHoverer()->HoveredCoordinate();

        // if (_<MouseInput>().LeftButton().PressedPickResult())
        // {
        //     player.SetDestination(hoveredCoord);
        // }

        // auto dest = player.Destination();

        // if (dest.x != -1 && dest.y != -1)
        // {
        //     if (Ticks() > player.TicksLastMove() + 1000/player.MovementSpeed())
        //     {
        //         auto playerPos = player.Position();
        //         if (playerPos.x < dest.x)
        //         {
        //             player.MoveEast();
        //         }
        //         if (playerPos.x > dest.x)
        //         {
        //             player.MoveWest();
        //         }
        //         if (playerPos.y < dest.y)
        //         {
        //             player.MoveSouth();
        //         }
        //         if (playerPos.y > dest.y)
        //         {
        //             player.MoveNorth();
        //         }
        //         player.SetTicksLastMove(Ticks());
        //     }
        // }
    }
}