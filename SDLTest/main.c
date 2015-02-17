#include "common.h"

int main(int argc, char* args[]) {

	// Main game loop
	Window window;
	window.height = SCREEN_HEIGHT;
	window.width = SCREEN_WIDTH;
	window.bpp = 32;

	if (init(&window)) {

		// TODO(ekollof): Temporary.
		SDL_Surface *marbles;
		SDL_Texture *mbTexture;
		marbles = SDL_LoadBMP("assets/MARBLES.BMP");
		if (!marbles) {
			log_error("Could not load bmp.\n");
			return 0;
		}
		mbTexture = loadTexture(&window, marbles);


		Running = TRUE;
		while (Running) {
			uint8_t *keys = scanKeyboard();
			handleKeys(keys);
			handleEvents(&window);
			render(&window, mbTexture);
		}
		cleanup(&window);
	}	

	return 0;
}