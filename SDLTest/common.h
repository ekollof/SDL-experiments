#ifndef _COMMON_H
#define _COMMON_H
#endif

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
#define TILE_WIDTH 16
#define TILE_HEIGHT 16
#define MAXTILES 500 // Arbitrary value.
#define MAXTILES_X MAXTILES / 2
#define MAXTILES_Y MAXTILES / 2

#define log_error(x, ...) SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, x, __VA_ARGS__);
#define log_info(x, ...) SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, x, __VA_ARGS__);
#define log_debug(x, ...) SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_DEBUG, x, __VA_ARGS__);

/* struct for keeping things together */

typedef struct {
	SDL_Window *window;
	SDL_Surface *mainsurface;
	SDL_Renderer *renderer;
	int fullscreen;
	int width;
	int height;
	int bpp;
} Window;

typedef struct {
	SDL_Surface *tilemap;
	SDL_Surface *tile[MAXTILES_X][MAXTILES_Y];
	int maxX;
	int maxY;
	int numtiles;
} Tilemap;

/* Globals (USE SPARINGLY PLEASE)*/
extern int Running;

//Screen dimension constants
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;


/* main.c */


/* events.c */
extern void handleEvents(Window *window);

/* keyboard.c */
extern Uint8 *scanKeyboard(void);
extern void handleKeys(const Uint8 *keys);

/* init.c */
extern int init(Window *window);
extern void cleanup(Window *window);
extern void init_img(void);

/* video.c */
extern int render(Window *window, SDL_Texture *frame, int angle);
extern SDL_Texture *loadTexture(Window *window, SDL_Surface *surf);

/* window.c */
extern int handleWindowEvent(SDL_Event *event, Window *window);

/* assets.c */
extern void loadTileMap(char *path, Window *window, Tilemap *tilemap);
extern SDL_Surface *getTile(SDL_Surface *tilemap, int indexX, int indexY);

/* levels.c */
extern SDL_Surface *genCaveLevel(Window *window, Tilemap *cavemap);