#include "common.h"

void handleEvents(void) {
	SDL_Event event;
	
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		Running = FALSE;
		break;
	default:
		break;
	}
}