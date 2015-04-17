#include "gamestate.h"

SDL_Texture *loadTexture(Window *window, SDL_Surface *surf) {

	SDL_Texture *texture = NULL;

	texture = SDL_CreateTextureFromSurface(window->renderer, surf);
	if (!texture) {
		log_error("No texture? :(", NULL);
	}

	return texture;
}

int render(Window *window, SDL_Texture *frame, SDL_Rect *camera, int angle) {
	int success = TRUE;
	SDL_RendererFlip flip = SDL_FLIP_NONE;

	SDL_RenderClear(window->renderer);
	SDL_RenderCopyEx(window->renderer, frame, camera, NULL, angle, NULL, flip);
	SDL_RenderPresent(window->renderer);

	return success;
}
