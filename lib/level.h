#pragma once

#include "tile.h"
#include "point.h"

#define MAX_WATER 100
#define MAX_UNITS 100

enum class UnitType {
	truck,
	heli,
	boat
};

class Unit {
public:

	UnitType type;
	Point position;
	Point size;
	Point direction;

	Unit();
	Unit(UnitType type, Point position, Point direction);

};

class Water {
public:

	Point position;
	Point direction;

	Water();
	Water(Point position, Point direction);

};

class Level {
public:

	Point numTiles;
	Tile** tiles;
	int turnNum;

	// spreadable water objects
	Water water[MAX_WATER];
	int numWater;

	Unit units[MAX_UNITS];
	int numUnits;

	// constructors
	Level();
	Level(Point numTiles);
	Level(int numTilesX, int numTilesY);

	// functions
	bool isGameLost();
	bool isGameWon();
	bool placeUnit(UnitType unit, Point position, Point direction);
	bool placeWater(Point position, Point direction);
	void spreadWater();
	void spreadFire();
};
