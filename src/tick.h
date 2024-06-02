#pragma once

#include "def.h"

void tick()
{
    int wait = TARGET_TICK - (SDL_GetTicks() - previous_tick);

    if (wait > 0 && wait <= TARGET_TICK) SDL_Delay(wait);

    delta_tick = (SDL_GetTicks() - previous_tick) / 1000.0F;
    previous_tick = SDL_GetTicks();
}