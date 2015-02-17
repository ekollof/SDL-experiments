#include "common.h"

int render(Window *window, SDL_Surface *surf) {
	int success = TRUE;

	SDL_Rect myRect;
	myRect.x = 0;
	myRect.y = 0;
	myRect.w = window->width;
	myRect.h = window->height;

	SDL_BlitScaled(surf, NULL, window->mainsurface, &myRect);
	SDL_UpdateWindowSurface(window->window);

	return success;
}