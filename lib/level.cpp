#include "level.h"
#include "tile.h"
#include "point.h"

Level::Level() {
	Level(0, 0);
}

Level::Level(Point numTiles) {
	Level::Level((int)numTiles.x, (int)numTiles.y);
}

Level::Level(int numTilesX, int numTilesY) {
	numTiles = { (double)numTilesX, (double)numTilesY };
	Tile** tiles = new Tile * [(int)numTiles.x];
	for (int i = 0; i < numTiles.x; i++)
		tiles[i] = new Tile[(int)numTiles.y];
	this->tiles = tiles;
}

bool Level::isGameLost() {
	// check if entire grid is fire

	for (int i = 0; i < numTiles.x; i++)
		for (int j = 0; j < numTiles.y; j++)
			if (tiles[i][j].tileType != TileType::fire)
				return false;

	return true;
}

bool Level::isGameWon() {
	// check if entire grid is not fire

	for (int i = 0; i < numTiles.x; i++)
		for (int j = 0; j < numTiles.y; j++)
			if (tiles[i][j].tileType == TileType::fire)
				return false;

	return true;
}