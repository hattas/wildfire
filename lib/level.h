#ifndef LEVEL_H
#define LEVEL_H

#include "tile.h"
#include "point.h"

class Level {
public:
	// members
	Point numTiles;
	Tile** tiles;

	// constructors
	Level();
	Level(Point numTiles);
	//Level(int numTilesX, int numTilesY);
	Level(int numTilesX, int numTilesY);

	// functions
};

#endif