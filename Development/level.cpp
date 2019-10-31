#include "level.h"
#include "tile.h"

Level::Level() {
	Level(0, 0);
}

Level::Level(Point numTiles) {
	Level::Level(numTiles.x, numTiles.y);
}

Level::Level(float numTilesX, float numTilesY) {
	numTiles = { numTilesX, numTilesY };
	Tile** tiles = new Tile * [(int) numTiles.x];
	for (int i = 0; i < numTiles.x; i++)
		tiles[i] = new Tile[(int) numTiles.y];
	this->tiles = tiles;
}