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
};

typedef struct gamestate {
	int running;
	int gameStarted;
	int fps;
} Gamestate;

#endif