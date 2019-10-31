#ifndef LEVEL_H
#define LEVEL_H

#include "tile.h"
#include "geometry.h"

class Level {
public:
	// members
	Pointi numTiles;
	Tile** tiles;

	// constructors
	Level();
	Level(Pointi numTiles);
	//Level(int numTilesX, int numTilesY);
	Level(int numTilesX, int numTilesY);

	// functions
};

#endif