#include "def.h"
#include "line.h"
#include "tick.h"
#include "input.h"
#include "screen.h"
#include "render.h"

// collision flags
bool flag_x, flag_y;

// ball reset
bool flag_reset;
float reset = RESET_COOLDOWN;

void loop()
{
    if (!flag_reset)
    {
        // translate the ball
        ball.x += flag_x ? BALL_SPEED * delta_tick : -BALL_SPEED * delta_tick;
        ball.y += flag_y ? BALL_SPEED * delta_tick : -BALL_SPEED * delta_tick;
    }

    // ball y position after any player scores
    int reset_position = rand() % (HEIGHT - 1 - 0 + 1) + 0;

    // ball y direction after any player scores
    int reset_direction = rand() % (1 - 0 + 1) + 0;
    
    // left & right collision
    if (ball.x <= 0 || ball.x >= WIDTH - 8 * BALL_SIZE)
    {
        flag_reset = TRUE;
        ball.color = BLACK;
    }

    if (ball.y <= 0) // ceiling collision
    {
        flag_y = TRUE;
    }
    else if (ball.y >= HEIGHT - 8 * BALL_SIZE) // floor collision
    {
        flag_y = FALSE;
    }

    // left player collision
    if (ball.x - 8 * BALL_SIZE <= player_left.x && ball.x >= player_left.x - 4 &&
        ball.y >= player_left.y && ball.y <= player_left.y + 8 * PLAYER_SIZE)
    {
        flag_x = TRUE;
    }

    // right player collision
    if (ball.x + 8 * BALL_SIZE >= player_right.x && ball.x <= player_right.x + 4 &&
        ball.y >= player_right.y && ball.y <= player_right.y + 8 * PLAYER_SIZE)
    {
        flag_x = FALSE;
    }

    // reset the ball upon scoring
    if (flag_reset && reset > 0)
    {
        reset -= 1 * delta_tick;
    }
    else if (reset <= 0)
    {
        ball.x = WIDTH / 2 - BALL_SIZE * 4;
        ball.y = reset_position;
        ball.color = WHITE;

        flag_y = reset_direction ? TRUE : FALSE;

        reset = RESET_COOLDOWN;
        flag_reset = FALSE;
    }
}

int main(int argc, char* agrv[])
{
    screen_create();

    for (;;)
    {
        input();
        tick();

        screen_clear(BLACK);

        loop();

        line(WIDTH / 2 - 1, 0, WIDTH / 2 - 1, HEIGHT - 1, WHITE, DASHED);
        line(WIDTH / 2, 0, WIDTH / 2, HEIGHT - 1, WHITE, DASHED);
        line(WIDTH / 2 + 1, 0, WIDTH / 2 + 1, HEIGHT - 1, WHITE, DASHED);

        render(layout_ball, ball.x, ball.y, BALL_SIZE, ball.color);
        render(layout_player, player_left.x, player_left.y, PLAYER_SIZE, player_left.color);
        render(layout_player, player_right.x, player_right.y, PLAYER_SIZE, player_right.color);

        screen_update();
    }

    return 0;
}