//
//  Copyright (C) 2024 Andreas Åkerberg.
//
#include "SDLDeleter.h"
//
//  SDLDeleter class implementation.
//
namespace JourneyOfDreams
{
   void SDLDeleter::operator()(SDL_Window *window) {
      //free allocated SDL window object
      SDL_DestroyWindow(window);
   }
   void SDLDeleter::operator()(SDL_Renderer *renderer) {
      //free allocated SDL renderer object
      SDL_DestroyRenderer(renderer);
   }
   void SDLDeleter::operator()(SDL_Surface *surface) {
      //free allocated SDL surface object
      SDL_FreeSurface(surface);
   }
   void SDLDeleter::operator()(SDL_Texture *texture) {
      //free allocated SDL texture object
      SDL_DestroyTexture(texture);
   }
   void SDLDeleter::operator()(TTF_Font *font) {
      //free allocated SDL_ttf font object
      TTF_CloseFont(font);
   }
} // namespace JourneyOfDreams
