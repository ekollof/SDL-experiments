#include "gamestate.h"

SDL_Surface *genCaveLevel(Window *window, Tilemap *tilemap, Level *leveldata) {

	// TODO(ekollof): Just use window size for now. Use bigger surfaces later.
	
	int i,j = 0;
	int levelsize = window->width * window->height;
	int levelx = window->width;
	int levely = window->height;
	int windowtiles = levelsize / TILE_WIDTH;
	int columns = window->width / TILE_WIDTH;
	int rows = window->height / TILE_HEIGHT;
	SDL_Rect tileRect;

	// Our canvas to blit tiles to.
	SDL_Surface *level = SDL_CreateRGBSurface(0, levelx, levely, window->bpp, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);

	// Just pick random tiles for now. 
	for (i = 0; i < columns; i++) {
		for (j = 0; j < rows; j++) {

			int tilex = 0;
			int tiley = 0;

			if (leveldata->level[i][j]) {
				tilex = 8;
				tiley = 0;
			} else {
				tilex = 1;
				tiley = 1;
			}

			tileRect.x = i * TILE_WIDTH;
			tileRect.y = j * TILE_HEIGHT;
			tileRect.w = TILE_WIDTH;
			tileRect.h = TILE_HEIGHT;
			
			// log_info("Placing tile at  (%d,%d)\n", i, j);
			if (SDL_BlitSurface(tilemap->tile[tilex][tiley], NULL, level, &tileRect)) {
				log_error("SDL_BlitSurface failed for tile (%d,%d)\n", i, j);
			}
		}
	}
	return level;
}

void initMap(int map[][MAXTILES_X], int xx, int yy, float chance) {
	int i, j = 0;
	float alivechance = chance;

	log_info("%d %d", xx, yy)

	for (i = 0; i < xx; i++) {
		for (j = 0; j < yy; j++) {

			float random = (float) rand() / (float) RAND_MAX;
			if (random < alivechance) {
				log_info("Placing point at (%d,%d)\n", i, j);
				map[i][j] = TRUE;
			} else {
				map[i][j] = FALSE;
			}
		}
	}
}

void copyMap(int map[][MAXTILES_X], int newmap[][MAXTILES_X], int columns, int rows) {
	int x, y = 0;

	for (x = 0; x < columns; x++) {
		for (y = 0; y < rows; y++) {
			map[x][y] = newmap[x][y];
		}
	}
}

void growCaves2(int map[][MAXTILES_X], int xx, int yy, int blimit, int dlimit) {
	int x, y = 0;

	for (x = 0; x < xx; x++) {
		for (y = 0; y < yy; y++) {
			int neighbors = checkNeighbor(map, x, y, yy, xx);
			if (map[x][y]) {
				if (neighbors < dlimit)
					map[x][y] = FALSE;
				else
					map[x][y] = TRUE;
			} else {
				if (neighbors > blimit)
					map[x][y] = TRUE;
				else
					map[x][y] = FALSE;
			}
		}
	}
}

void growCaves(int map[][MAXTILES_X], int newmap[][MAXTILES_X], int xx, int yy, int blimit, int dlimit) {
	int x, y = 0;

	for (x = 0; x < xx; x++) {
		for (y = 0; y < yy; y++) {
			int neighbors = checkNeighbor(map, x, y, yy, xx);
			if (map[x][y]) {
				if (neighbors < dlimit)
					newmap[x][y] = FALSE;
				else
					newmap[x][y] = TRUE;
			} else {
				if (neighbors > blimit)
					newmap[x][y] = TRUE;
				else
					newmap[x][y] = FALSE;
			}
			

		}
	}
}

int checkNeighbor(int map[][MAXTILES_X], int x, int y, int yy, int xx) {
	int count = 0;
	int i, j = 0;

	for (i = -1; i < 2; i++) {
		for (j = -1; j < 2; j++) {
			int neigh_x = x + i;
			int neigh_y = y + j;

			if (i == 0 && j == 0) {
			} else
			// Don't count ourselves.
			if (neigh_x < 0 || neigh_y < 0 || neigh_x >= xx  || neigh_y >= yy) {
				// Are we looking at an edge?
				count += 1;
				continue;
			} else
			// log_info("Checking %d %d\n", neigh_x, neigh_y)
			if (map[neigh_x][neigh_y]) {
				count += 1;
			}
			
		}
	}
	return count;
}

void fixWalls(Level *level) {
	// Find alls and corners and fix them up.
	// 
	// 0 == Open space
	// 1 == Filled space
	// 2 == vertical wall left
	// 3 == vertical wall right
	// 4 == horizontal wall left
	// 5 == horizontal wall right
	// 6 == top left corner
	// 7 == top right corner
	// 8 == bottom left corner
	// 9 == bottom right corner

	int x, y = 0;
	int xtiles = level->levelX / TILE_WIDTH;
	int ytiles = level->levelY / TILE_HEIGHT;

	char *neighbors;

	for (x = 0; x < xtiles; x++) {
		for (y = 0; y < ytiles; y++) {
			neighbors = findTileType(level, x, y, xtiles, ytiles);
			log_info("Map: %s", neighbors);
			SDL_free(neighbors);
		}
	}

}

char *findTileType(Level *level, int x, int y, int xx, int yy) {
	int i, j = 0;
	int occupied = 0;
	char *ret;
	
	ret = SDL_calloc(1, 9);

	/*
	Order of processing.
	1 4 6
	2   7
	3 5 8
	*/

	for (i = -1; i < 2; i++) {
		for (j = -1; j < 2; j++) {
			int neigh_x = x + i;
			int neigh_y = y + j;

			if (i == 0 && j == 0) {
				// Us. Next.
			} else if (neigh_x < 0 || neigh_y < 0 || neigh_x >= xx || neigh_y >= yy) {
					log_info("At level edge\n");
					ret[occupied] = '1';
				} else
					log_info("Checking %d %d\n", neigh_x, neigh_y)
					if (level->level[neigh_x][neigh_y]) {
						ret[occupied] = '1';
					} else {
						ret[occupied] = '0';
					}
				occupied++;
		}
	}
	ret[9] = '\0';
	return ret;
}
