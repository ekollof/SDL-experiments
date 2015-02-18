#include "gamestate.h"

Uint8 *scanKeyboard(void) {
	const Uint8 *keyboard;
	
	SDL_PumpEvents();
	keyboard = SDL_GetKeyboardState(NULL);
	return keyboard;
}

void handleKeys(const Uint8 *keys) {

	/* check which key is pressed */
	if (keys[SDL_SCANCODE_ESCAPE]) {
		log_info("Escape was pressed.\n");
		Running = FALSE;
	}

}