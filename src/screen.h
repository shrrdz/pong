#pragma once

#include "def.h"

SDL_Window      *window;
SDL_Renderer    *renderer;
SDL_Texture     *texture;

uint32_t color_buffer[WIDTH * HEIGHT];

void screen_create()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
}

void screen_clear(uint32_t color)
{    
    for (int i = 0; i < WIDTH * HEIGHT; i++)
    {
        color_buffer[i] = color;
    }
}

void screen_pixel(int x, int y, uint32_t color)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        color_buffer[y * WIDTH + x] = color;
    }
}

void screen_update()
{
    SDL_UpdateTexture(texture, NULL, color_buffer, WIDTH * sizeof(uint32_t));

    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}