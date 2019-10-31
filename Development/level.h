#ifndef LEVEL_H
#define LEVEL_H

#include "tile.h"
#include "geometry.h"

class Level {
public:
	// members
	Point numTiles;
	Tile** tiles;

	// constructors
	Level();
	Level(Point numTiles);
	//Level(int numTilesX, int numTilesY);
	Level(float numTilesX, float numTilesY);

	// functions
};

#endif