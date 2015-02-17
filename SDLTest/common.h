#include <SDL.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

/* struct for keeping things together */

typedef struct tagSDLinfo {
	SDL_Window *window;
	SDL_Surface *mainsurface; 
	unsigned int fullscreen;
	unsigned int width;
	unsigned int height;
	unsigned int bpp;
} Window;

/* Globals (USE SPARINGLY PLEASE)*/
extern int Running;

//Screen dimension constants
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;


/* main.c */


/* events.c */
extern void handleEvents(void);

/* keyboard.c */
extern Uint8 *scanKeyboard(void);
extern void handleKeys(const Uint8 *keys);

/* logging.c */
extern void log_info(char *fmt, ...);
extern void log_debug(char *fmt, ...);

/* init.c */
extern int init(Window *window);
extern void cleanup(Window *window);

/* video.c */
extern int render(Window *window, SDL_Surface *surf);