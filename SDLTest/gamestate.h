#ifndef _GAMESTATE_H
#define _GAMESTATE_H


#include "common.h"
#include "cproto.h"

typedef struct player {
	int posX;
	int posY;
	int health;
	Uint16 weapons;
	SDL_Texture *sprite;
} Player;

typedef struct projectile {
	int posX;
	int posY;
	int movetoX;
	int movetoY;
	int damage;
} Projectile;

typedef struct gamestate {
	int running;
	int gameStarted;
	int fps;
} Gamestate;

// 0 == Open space
// 1 == Filled space
// 2 == vertical wall left
// 3 == vertical wall right
// 4 == horizontal wall up
// 5 == horizontal wall down
// 6 == top left corner
// 7 == top right corner
// 8 == bottom left corner
// 9 == bottom right corner

#define TILE_OPEN 0
#define TILE_CLOSE 1
#define TILE_LVERT 2
#define TILE_RVERT 3
#define TILE_UHORZ 4
#define TILE_DHORZ 5
#define TILE_TLCORN 6
#define TILE_TRCORN 7
#define TILE_BLCORN 8
#define TILE_BRCORN 9

#define DIR_NONE 0
#define DIR_DLEFT 1
#define DIR_DOWN 2
#define DIR_DRIGHT 3
#define DIR_LEFT 4
#define DIR_RIGHT 6
#define DIR_ULEFT 7
#define DIR_UP 8
#define DIR_URIGHT 9

#define MAX_SPEED 5

#endif
