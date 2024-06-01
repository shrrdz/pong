#pragma once

#include <SDL.h>

SDL_Event event;

void input()
{
    const uint8_t *key = SDL_GetKeyboardState(NULL);

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: SDL_Quit(); exit(0);
                }
            break;

            case SDL_QUIT: SDL_Quit(); exit(0);
        }
    }
}