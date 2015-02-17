#include "common.h"

int init(Window *window) {
	int success = TRUE;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = FALSE;
	} else {
		//Create window
		window->window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		if (window->window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = FALSE;
		} else {

			//Get window surface
			window->mainsurface = SDL_GetWindowSurface(window->window);
			window->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (!window->renderer) {
				printf("Could not get renderer! SDL Error %s\n", SDL_GetError());
				success = FALSE;
			}

		}
	}

	return success;
}

void cleanup(Window *window) {
	//Destroy window
	SDL_DestroyWindow(window->window);

	//Quit SDL subsystems
	SDL_Quit();
}