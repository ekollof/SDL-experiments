#include "common.h"

SDL_Texture *loadTexture(Window *window, SDL_Surface *surf) {

	SDL_Texture *texture = NULL;

	texture = SDL_CreateTextureFromSurface(window->renderer, surf);
	if (!texture) {
		log_error("No texture? :(");
	}

	return texture;
}

int render(Window *window, SDL_Texture *frame) {
	int success = TRUE;
	SDL_Rect myRect;

	myRect.x = 0;
	myRect.y = 0;
	myRect.w = window->width;
	myRect.h = window->height;

	SDL_RenderClear(window->renderer);
	SDL_RenderCopy(window->renderer, frame, NULL, &myRect);
	SDL_RenderPresent(window->renderer);

	return success;
}