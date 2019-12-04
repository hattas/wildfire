#pragma once

#include "tile.h"
#include "point.h"

class Level {
public:
	
	Point numTiles;
	Tile** tiles;

	// constructors
	Level();
	Level(Point numTiles);
	Level(int numTilesX, int numTilesY);

	// functions
};
