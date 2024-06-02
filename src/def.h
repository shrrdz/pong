#pragma once

#include <SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>

//-----------------------------------------------------//

#define TRUE            1
#define FALSE           0

typedef int             bool;

//-----------------------------------------------------//

#define BLACK           0x000000
#define WHITE           0xFFFFFF

//-----------------------------------------------------//

#define WIDTH           800
#define HEIGHT          600

#define FPS             60
#define TARGET_TICK     (float) 1000 / FPS

#define BALL_SIZE       1
#define BALL_SPEED      160

#define PLAYER_SIZE     8
#define PLAYER_SPEED    180

//-----------------------------------------------------//

float previous_tick, delta_tick;

int player_left_x = 0;
int player_left_y = HEIGHT / 2 - PLAYER_SIZE * 4;

int player_right_x = WIDTH - PLAYER_SIZE;
int player_right_y = HEIGHT / 2 - PLAYER_SIZE * 4;

//-----------------------------------------------------//

typedef enum { FULL, DOTTED, DASHED, DASH_DOTTED } line_pattern;

//-----------------------------------------------------//