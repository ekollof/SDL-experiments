#ifndef _GAMESTATE_H
#define _GAMESTATE_H
#endif

#include "common.h"

typedef struct {
	int posX;
	int posY;
	int health;
	Uint16 weapons;
	SDL_Texture *sprite;
} Player;

typedef struct {
	int running;
	int gameStarted;

} Gamestate;