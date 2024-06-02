#include "def.h"
#include "line.h"
#include "tick.h"
#include "input.h"
#include "screen.h"
#include "render.h"

// ball position
int ball_x = WIDTH / 2 - BALL_SIZE * 4;
int ball_y = HEIGHT / 2 - BALL_SIZE * 4;

// collision flags
bool flag_x, flag_y;

void loop()
{
    // translate the ball
    ball_x += flag_x ? BALL_SPEED * delta_tick : -BALL_SPEED * delta_tick;
    ball_y += flag_y ? BALL_SPEED * delta_tick : -BALL_SPEED * delta_tick;

    if (ball_x <= 0) // left collision
    {
        flag_x = TRUE;
    }
    else if (ball_x >= WIDTH - 8 * BALL_SIZE) // right collision
    {
        flag_x = FALSE;
    }

    if (ball_y <= 0) // ceiling collision
    {
        flag_y = TRUE;
    }
    else if (ball_y >= HEIGHT - 8 * BALL_SIZE) // floor collision
    {
        flag_y = FALSE;
    }

    // player collision
    if (ball_x - 8 * BALL_SIZE <= player_x&& ball_y >= player_y && ball_y <= player_y + 8 * PLAYER_SIZE)
    {
        flag_x = TRUE;
    }
}

int main(int argc, char* agrv[])
{
    screen_create();

    for (;;)
    {
        input();
        tick();

        screen_clear(0x000000);

        loop();

        line(400, 0, 400, HEIGHT - 1, 0xFFFFFF, 2);

        render(layout_ball, ball_x, ball_y, BALL_SIZE, 0xFFFFFF);
        render(layout_player, player_x, player_y, PLAYER_SIZE, 0xFFFFFF);

        screen_update();
    }

    return 0;
}