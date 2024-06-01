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

#define WIDTH           800
#define HEIGHT          600

#define FPS             60
#define TARGET_TICK     (float) 1000 / FPS

#define BALL_SIZE       1

#define PLAYER_SIZE     8

//-----------------------------------------------------//

float previous_tick, delta_tick;

//-----------------------------------------------------//