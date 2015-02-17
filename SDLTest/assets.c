#include "common.h"

SDL_Surface *loadTileMap(char *path, Window *window) {
	SDL_Surface *tmp;
	SDL_Surface *image;

	tmp = IMG_Load(path);
	image = SDL_ConvertSurface(tmp, window->mainsurface->format, 0);
	if (!image)
		log_error("Optimization failed: %s\n", SDL_GetError());
	SDL_FreeSurface(tmp);

	return image;
}

SDL_Surface *getTile(SDL_Surface *tilemap, int indexX, int indexY) {

	assert(tilemap != NULL);

	SDL_Surface *tile = SDL_CreateRGBSurface(0, TILE_WIDTH, TILE_HEIGHT, 32, 0xFF000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
	SDL_Rect tileRect;

	int maxhtiles = tilemap->w / TILE_WIDTH - 1;
	int maxvtiles = tilemap->h / TILE_HEIGHT - 1;

	if (indexX > maxhtiles || indexY > maxvtiles) {
		log_error("Tile index (%d, %d) out of bounds. Max X: %d  Max Y; %d",
			indexX,
			indexY,
			maxhtiles,
			maxvtiles);
	}
	


	tileRect.x = indexX * TILE_WIDTH;
	tileRect.y = indexY * TILE_HEIGHT;
	tileRect.w = TILE_WIDTH;
	tileRect.h = TILE_HEIGHT;

	if (SDL_BlitSurface(tilemap, &tileRect, tile, NULL) < 0) {
		log_error("Tilerec failed. %s", SDL_GetError());
		return NULL;
	}

	return tile;
}

