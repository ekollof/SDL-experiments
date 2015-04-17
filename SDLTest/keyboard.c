#include "gamestate.h"

Uint8 *scanKeyboard(void) {
	Uint8 *keyboard;
	
	SDL_PumpEvents();
	keyboard = SDL_GetKeyboardState(NULL);
	return keyboard;
}

void handleKeys(Uint8 *keys, Window *window) {

	int speed = 2;

	/* check which key is pressed */
	if (keys[SDL_SCANCODE_ESCAPE]) {
		log_info("Escape was pressed.\n", NULL);
		Running = FALSE;
	}

	if (keys[SDL_SCANCODE_W]) {
		cameraDirection(window, DIR_UP, speed);
	}
	if (keys[SDL_SCANCODE_S]) {
		cameraDirection(window, DIR_DOWN, speed);
	}
	if (keys[SDL_SCANCODE_A]) {
		cameraDirection(window, DIR_LEFT, speed);
	}
	if (keys[SDL_SCANCODE_D]) {
		cameraDirection(window, DIR_RIGHT, speed);
	}
	if (keys[SDL_SCANCODE_UP]) {
		cameraDirection(window, DIR_UP, speed);
	}
	if (keys[SDL_SCANCODE_DOWN]) {
		cameraDirection(window, DIR_DOWN, speed);
	}
	if (keys[SDL_SCANCODE_LEFT]) {
		cameraDirection(window, DIR_LEFT, speed);
	}
	if (keys[SDL_SCANCODE_RIGHT]) {
		cameraDirection(window, DIR_RIGHT, speed);
	}
}
