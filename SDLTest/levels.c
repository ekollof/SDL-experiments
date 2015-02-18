#include "gamestate.h"

SDL_Surface *genCaveLevel(Window *window, Tilemap *cavemap) {

	// TODO(ekollof): Just use window size for now. Use bigger surfaces later.
	
	int i,j = 0;
	int levelsize = window->width * window->height;
	int levelx = window->width;
	int levely = window->height;
	int windowtiles = levelsize / TILE_WIDTH;
	int columns = window->width / TILE_WIDTH;
	int rows = window->height / TILE_HEIGHT;
	SDL_Rect tileRect;

	// Generate map.
	// TODO(emiel): move this somewhere else.
	if (!generateCaveMap(cavemap->map, columns, rows)) {
		log_error("map generation failed.");
		return NULL;
	}
	
	// Our canvas to blit tiles to.
	SDL_Surface *level = SDL_CreateRGBSurface(0, levelx, levely, window->bpp, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
	
	// Just pick random tiles for now. 
	for (i = 0; i < columns; i++) {
		for (j = 0; j < rows; j++) {
			//int tilex = rand() % cavemap->maxX;
			//int tiley = rand() % cavemap->maxY;
			int tilex = 1;
			int tiley = 1;

			tileRect.x = i * TILE_WIDTH;
			tileRect.y = j * TILE_HEIGHT;
			tileRect.w = TILE_WIDTH;
			tileRect.h = TILE_HEIGHT;
			
			// log_info("Placing tile at  (%d,%d)\n", i, j);
			if (SDL_BlitSurface(cavemap->tile[tilex][tiley], NULL, level, &tileRect)) {
				log_error("SDL_BlitSurface failed for tile (%d,%d)\n", i, j);
			}
		}

	}

	return level;
}

int generateCaveMap(int **map, int width, int height) {
	// Generate cave map using cellular automata. Reference: http://gamedevelopment.tutsplus.com/tutorials/generate-random-cave-levels-using-cellular-automata--gamedev-9664
	size_t memsize = 0;
	size_t estimated = sizeof(int) * width * height;
	map = NULL;
	int i, j = 0;

	// Allocate memory for map (multidimensional array)
	if ((map = malloc(height * sizeof(int *))) == NULL) {
		log_error("malloc cols\n");
		return FALSE;
	}
	memsize += height * sizeof(int *);
	for (i = 0; i < height; i++) {
		if ((map[i] = malloc(width * sizeof(int))) == NULL) {
			log_error("malloc rows\n");
			return FALSE;
		}
		memsize += width * sizeof(int);
	}
	log_info("Allocated memory for map data. Expected %d bytes, got %d.", (int)estimated, (int)memsize);
	assert(estimated < memsize);



	return TRUE;
}