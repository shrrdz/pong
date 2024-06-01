#pragma once

#include "def.h"
#include "screen.h"

const int layout_ball[8][8] =
{
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
};

const int layout_player[8][8] =
{
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,    
};

void render(const int ch[8][8], float x, float y, int scale, int color)
{
    int size = 8 * scale;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int r = j / scale;
            int c = i / scale;

            if (ch[r][c] == 1)
            {
                screen_pixel(i + x, j + y, color);
            }
        }
    }
}