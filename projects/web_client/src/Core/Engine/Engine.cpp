#include "Engine.h"
#include "Cursor/Cursor.h"
#include "Graphics/Graphics.h"
#include "Net/NetClient.h"
#include "PollEvents.h"
#include "ScenesCore/SceneManager.h"

namespace zw {
  Engine::Engine() {
    _<NetClient>();    // Touch NetClient to initialize it
    _<Graphics>();     // Touch Graphics to initialize it
    _<SceneManager>(); // Touch SceneManager to initialize it
    _<Cursor>();       // Touch Cursor to initialize it
  }

  void Engine::Reset() {
    _<Cursor>().ResetStyle();
    _<Graphics>().ClearCanvas();
    SDL_SetHint(SDL_HINT_ENABLE_SCREEN_KEYBOARD, "1");
    SDL_StartTextInput();
  }

  void Engine::HandleInput() {
    PollEvents();
  }

  void Engine::Update() {
    _<SceneManager>().UpdateCurrentScene();
  }

  void Engine::UpdateNet() {
    _<NetClient>().Update();
  }

  void Engine::Render() {
    _<SceneManager>().RenderCurrentScene();
    _<Cursor>().Render();
  }

  void Engine::UpdatePostRender() {
    _<SceneManager>().UpdatePostRenderCurrentScene();
  }
  
  void Engine::PresentCanvas() {
    _<Graphics>().PresentCanvas();
  }
}
