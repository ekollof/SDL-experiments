#include "common.h"

int main(int argc, char* args[]) {

	// Main game loop
	Window window;
	window.height = SCREEN_HEIGHT;
	window.width = SCREEN_WIDTH;
	window.bpp = 32;


	if (init(&window)) {

		init_img();

		// Game assets
		SDL_Surface *cavemap = loadTileMap("assets/cave.png", &window);
		
		SDL_Surface *tile = getTile(cavemap, 0, 0);

		SDL_Texture *frame = loadTexture(&window, tile);

		Running = TRUE;
		while (Running) {
			uint8_t *keys = scanKeyboard();
			handleKeys(keys);
			handleEvents(&window);
			render(&window, frame);
		}
		cleanup(&window);
	}	

	return 0;
}