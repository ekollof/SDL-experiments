#include "gamestate.h"

int main(int argc, char* args[]) {

	// Main game loop
	Window window;
	window.height = SCREEN_HEIGHT;
	window.width = SCREEN_WIDTH;
	window.bpp = 32;
	int angle = 0;

	

	if (init(&window)) {


		// SDL_Image (for tilemaps)
		init_img();

		// Seed RNG
		srand((int)time(NULL));

		// Game assets
		Tilemap cavemap;
		loadTileMap("assets/cave.png", &window, &cavemap);
		SDL_Surface *level = genCaveLevel(&window, &cavemap);

		SDL_Texture *frame = loadTexture(&window, level);

		Running = TRUE;
		while (Running) {
			uint8_t *keys = scanKeyboard();
			handleKeys(keys);
			handleEvents(&window);

			render(&window, frame, angle);
		}
		cleanup(&window);
	}	

	return 0;
}