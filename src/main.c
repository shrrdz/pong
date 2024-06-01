#include "def.h"
#include "line.h"
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

        line(0, 0, WIDTH - 1, HEIGHT - 1, 0xFFFFFF);

        screen_update();
    }

    return 0;
}