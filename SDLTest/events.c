#include "gamestate.h"

void handleEvents(Window *window) {
	SDL_Event event;
	
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		Running = FALSE;
		cleanup(window);
		break;
	case SDL_WINDOWEVENT:
		handleWindowEvent(&event, window);
		break;
	default:
		break;
	}
}
