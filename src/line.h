#pragma once

#include "def.h"
#include "screen.h"

void line(float x0, float y0, float x1, float y1, uint32_t color, bool dashed)
{
    float run = x1 - x0;
    float rise = y1 - y0;

    bool steep = fabs(rise) > fabs(run);

    if (steep ? (y0 > y1) : (x0 > x1))
    {
        // swap both x and y endpoints
        x1 = x0 + x1 - (x0 = x1);
        y1 = y0 + y1 - (y0 = y1);
    }

    // slope
    float k = steep ? (run / rise) : (rise / run);
    // y-intercept
    float q = steep ? (x0 - k * y0) : (y0 - k * x0);

    int i = 0;

    for (int x = steep ? y0 : x0; steep ? (x <= y1) : (x <= x1); x++)
    {
        int y = k * x + q;

        screen_pixel(steep ? y : x, steep ? x : y, color);

        if (dashed)
        {
            i = (i < 8) ? (i + 1) : 0;

            if (i == 0)
            {
                x += 4;
            }
        }
    }
}