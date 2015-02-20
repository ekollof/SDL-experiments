#ifndef _CPROTO_H
#define _CPROTO_H


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
extern SDL_Surface *genCaveLevel(Window *window, Tilemap *tilemap, Level *leveldata);
extern void initMap(int map[][MAXTILES_X], int xx, int yy, float chance);
extern void copyMap(int map[][MAXTILES_X], int newmap[][MAXTILES_X], int columns, int rows);
extern void growCaves(int map[][MAXTILES_X], int newmap[][MAXTILES_X], int xx, int yy, int blimit, int dlimit);
extern void growCaves2(int map[][MAXTILES_X], int xx, int yy, int blimit, int dlimit);
extern int checkNeighbor(int map[][MAXTILES_X], int x, int y, int nrows, int ncolumns);
extern void fixWalls(Level *level);
extern int getTileType(char *pattern);
extern char *findTileType(Level *level, int x, int y, int xx, int yy);

#endif