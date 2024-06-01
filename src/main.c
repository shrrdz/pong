#include "def.h"
#include "line.h"
#include "tick.h"
#include "input.h"
#include "screen.h"
#include "render.h"

int main(int argc, char* agrv[])
{
    screen_create();

    for (;;)
    {
        input();
        tick();

        screen_clear(0x000000);

        render(layout_ball, WIDTH / 2 - BALL_SIZE * 4, HEIGHT / 2 - BALL_SIZE * 4, BALL_SIZE, 0xFFFFFF);
        render(layout_player, 0, HEIGHT / 2 - PLAYER_SIZE * 4, PLAYER_SIZE, 0xFFFFFF);

        screen_update();
    }

    return 0;
}