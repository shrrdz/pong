#pragma once

#include <SDL.h>

SDL_Event event;

void input()
{
    const uint8_t *key = SDL_GetKeyboardState(NULL);

    if (key[SDL_SCANCODE_W] && player_left_y > 0) player_left_y -= PLAYER_SPEED * delta_tick;
    if (key[SDL_SCANCODE_S] && player_left_y < HEIGHT - 8 * PLAYER_SIZE) player_left_y += PLAYER_SPEED * delta_tick;

    if (key[SDL_SCANCODE_UP] && player_right_y > 0) player_right_y -= PLAYER_SPEED * delta_tick;
    if (key[SDL_SCANCODE_DOWN] && player_right_y < HEIGHT - 8 * PLAYER_SIZE) player_right_y += PLAYER_SPEED * delta_tick;

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