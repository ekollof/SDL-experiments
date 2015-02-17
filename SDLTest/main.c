#include "common.h"

int main(int argc, char* args[]) {

	// Main game loop
	Window window;
	window.height = SCREEN_HEIGHT;
	window.width = SCREEN_WIDTH;
	window.bpp = 32;

	if (init(&window)) {

		SDL_Surface *marbles;
		marbles = SDL_LoadBMP("assets/MARBLES.BMP");
		if (!marbles) {
			log_info("Could not load bmp.\n");
			return 0;
		}

		Running = TRUE;
		while (Running) {
			uint8_t *keys = scanKeyboard();
			handleKeys(keys);
			handleEvents();
			render(&window, marbles);
		}
		cleanup(&window);
	}	

	return 0;
}