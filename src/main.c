#include <stdio.h>

#include "def.h"
#include "screen.h"

int main(int argc, char* agrv[])
{
    screen_create();

    for (;;)
    {
        screen_clear(0x000000);
        screen_update();
    }

    return 0;
}