#include "level.h"
#include "tile.h"

Level::Level() {
	Level(0, 0);
}

Level::Level(Pointi numTiles) {
	Level::Level(numTiles.x, numTiles.y);
}

Level::Level(int numTilesX, int numTilesY) {
	numTiles = { numTilesX, numTilesY };
	Tile** tiles = new Tile * [numTiles.x];
	for (int i = 0; i < numTiles.x; i++)
		tiles[i] = new Tile[numTiles.y];
	this->tiles = tiles;
}