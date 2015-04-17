#include "gamestate.h"

int handleWindowEvent(SDL_Event *event, Window *window) {

	switch (event->window.event) {
	case SDL_WINDOWEVENT_RESIZED:
		SDL_GetWindowSize(window->window, &window->width, &window->height);
		log_info("Window %d resized to %d x %d", event->window.windowID, window->width, window->height);
		break;
	case SDL_WINDOWEVENT_CLOSE:
		Running = FALSE;
		cleanup(window);
		break;
	default:
		break;
	}

	return TRUE;
}


void cameraDirection(Window *window, int direction, int speed) {



	if (speed > MAX_SPEED)
		speed = MAX_SPEED;


	switch (direction) {
	case DIR_DOWN:
		window->camera.y += speed;
		break;
	case DIR_UP:
		window->camera.y -= speed;
		break;
	case DIR_LEFT:
		window->camera.x -= speed;
		break;
	case DIR_RIGHT:
		window->camera.x += speed;
		break;
	default:
		break; // Do nothing
	}


	// log_info("Direction: %d", direction);

	if (window->camera.x + window->camera.w > SCREEN_WIDTH) {
		window->camera.x = SCREEN_WIDTH - window->camera.w;
		log_info("Hit right edge\n", NULL);
	}

	if (window->camera.x < 0) {
		window->camera.x = 0;
		log_info("Hit left edge\n", NULL);
	}

	if (window->camera.y < 0){
		window->camera.y = 0;
		log_info("Hit top edge\n", NULL);
	}

	if (window->camera.y + window->camera.h > SCREEN_HEIGHT) {
		window->camera.y = SCREEN_HEIGHT - window->camera.h;
		log_info("Hit bottom edge\n", NULL);
	}


	// log_info("Camera @ x: %d y: %d\n", window->camera.x, window->camera.y);
}
