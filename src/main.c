#include <stdio.h>

#include "def.h"
#include "tick.h"
#include "input.h"
#include "screen.h"

int main(int argc, char* agrv[])
{
    screen_create();

    for (;;)
    {
        input();
        tick();

        screen_clear(0x000000);
        screen_update();
    }

    return 0;
}