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

// ball reset
bool flag_reset;
float reset = RESET_COOLDOWN;

uint32_t ball_color = WHITE;

void loop()
{
    if (!flag_reset)
    {
        // translate the ball
        ball_x += flag_x ? BALL_SPEED * delta_tick : -BALL_SPEED * delta_tick;
        ball_y += flag_y ? BALL_SPEED * delta_tick : -BALL_SPEED * delta_tick;
    }

    // ball y position after any player scores
    int reset_position = rand() % (HEIGHT - 1 - 0 + 1) + 0;

    // ball y direction after any player scores
    int reset_direction= rand() % (1 - 0 + 1) + 0;
    
    // left & right collision
    if (ball_x <= 0 || ball_x >= WIDTH - 8 * BALL_SIZE)
    {
        flag_reset = TRUE;
        ball_color = BLACK;
    }

    if (ball_y <= 0) // ceiling collision
    {
        flag_y = TRUE;
    }
    else if (ball_y >= HEIGHT - 8 * BALL_SIZE) // floor collision
    {
        flag_y = FALSE;
    }

    // left player collision
    if (ball_x - 8 * BALL_SIZE <= player_left_x && ball_y >= player_left_y && ball_y <= player_left_y + 8 * PLAYER_SIZE)
    {
        flag_x = TRUE;
    }

    // right player collision
    if (ball_x + 8 * BALL_SIZE >= player_right_x && ball_y >= player_right_y && ball_y <= player_right_y + 8 * PLAYER_SIZE)
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
        ball_x = WIDTH / 2 - BALL_SIZE * 4;
        ball_y = reset_position;
        ball_color = WHITE;

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

        render(layout_ball, ball_x, ball_y, BALL_SIZE, ball_color);
        render(layout_player, player_left_x, player_left_y, PLAYER_SIZE, WHITE);
        render(layout_player, player_right_x, player_right_y, PLAYER_SIZE, WHITE);

        screen_update();
    }

    return 0;
}