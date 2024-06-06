#pragma once

#include <SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
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
#define PLAYER_OFFSET   16

#define RESET_COOLDOWN  3

//-----------------------------------------------------//

typedef struct { int x, y; uint32_t color; } entity;

typedef enum { FULL, DOTTED, DASHED, DASH_DOTTED } line_pattern;

//-----------------------------------------------------//

float previous_tick, delta_tick;

entity ball = { WIDTH / 2 - BALL_SIZE * 4, HEIGHT / 2 - BALL_SIZE * 4, WHITE };

entity player_left = { PLAYER_OFFSET, HEIGHT / 2 - PLAYER_SIZE * 4, WHITE };
entity player_right = { WIDTH - PLAYER_SIZE - PLAYER_OFFSET, HEIGHT / 2 - PLAYER_SIZE * 4, WHITE };

//-----------------------------------------------------//