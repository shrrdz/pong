#pragma once

#include "def.h"
#include "screen.h"

void line(float x0, float y0, float x1, float y1, uint32_t color, line_pattern pattern)
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

    switch (pattern)
    {
        case FULL:
            for (int x = steep ? y0 : x0; steep ? (x <= y1) : (x <= x1); x++)
            {
                int y = k * x + q;

                screen_pixel(steep ? y : x, steep ? x : y, color);
            }
        break;

        case DOTTED:
            for (int x = steep ? y0 : x0; steep ? (x <= y1) : (x <= x1); x += 4)
            {
                int y = k * x + q;

                screen_pixel(steep ? y : x, steep ? x : y, color);
            }
        break;

        case DASHED:
            for (int x = steep ? y0 : x0; steep ? (x <= y1) : (x <= x1); x++)
            {
                int y = k * x + q;

                screen_pixel(steep ? y : x, steep ? x : y, color);

                i = (i < 8) ? (i + 1) : 0;

                if (i == 0)
                {
                    x += 4;
                }
            }
        break;

        case DASH_DOTTED:
            for (int x = steep ? y0 : x0; steep ? (x <= y1) : (x <= x1); x++)
            {
                int y = k * x + q;

                screen_pixel(steep ? y : x, steep ? x : y, color);

                if (i < 8)
                {
                    i++;
                }
                else
                {
                    x += 4;
                    y = k * x + q;

                    screen_pixel(steep ? y : x, steep ? x : y, color);
                    
                    x += 4;
                    i = 0;
                }
            }
        break;
    }
}