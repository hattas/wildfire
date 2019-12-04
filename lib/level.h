#pragma once

#include "tile.h"
#include "point.h"

enum class UnitType {
	truck,
	heli,
	boat
};

class Level {
public:
	
	Point numTiles;
	Tile** tiles;

	// constructors
	Level();
	Level(Point numTiles);
	Level(int numTilesX, int numTilesY);

	// functions
	bool isGameLost();
	bool isGameWon();
	bool placeUnit(UnitType unit, int x, int y, int rotation);
	void spreadWater();
	void spreadFire();
};
