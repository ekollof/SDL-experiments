#include "common.h"

SDL_Texture *loadTexture(Window *window, SDL_Surface *surf) {

	SDL_Texture *texture = NULL;

	texture = SDL_CreateTextureFromSurface(window->renderer, surf);
	if (!texture) {
		log_error("No texture? :(");
	}

	return texture;
}

int render(Window *window, SDL_Texture *texture) {
	int success = TRUE;
	SDL_Rect myRect;
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	static double angle = 0;

	if (angle < 360) {
		angle++;
	} else {
		angle = 0;
	}

	myRect.x = 0;
	myRect.y = 0;
	myRect.w = window->width;
	myRect.h = window->height;

	SDL_RenderClear(window->renderer);
	SDL_RenderCopyEx(window->renderer, texture, NULL, &myRect, angle, NULL, flipType);
	SDL_RenderPresent(window->renderer);

	return success;
}