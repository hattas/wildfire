#include "level.h"
#include "tile.h"
#include "point.h"

Unit::Unit() {
	type = UnitType::truck;
	position.x = 0;
	position.y = 0;
	size.x = 1;
	size.y = 1;
	rotation = 0;
}

Unit::Unit(UnitType t, Point p, int r) {
	type = t;
	position = p;
	rotation = r;
	switch (type) {
	case UnitType::truck:
		size = { 1, 3 };
		break;
	case UnitType::boat:
		size = { 1, 3 };
		break;
	case UnitType::heli:
		size = { 2, 2 };
		break;
	default:
		size = { 1, 1 };
		break;
	}
}

Water::Water() {
	position = { 0, 0 };
	direction = { 1, 1 };
}

Water::Water(Point p, Point d) {
	position = p;
	direction = d;
}

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

	numUnits = 0;
	numWater = 0;
	turnNum = 1;
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

bool Level::placeUnit(UnitType unit, int x, int y, int rotation) {
	Unit newUnit = Unit(unit, { (double)x, (double)y }, rotation);

	// TODO: check if unit can be placed
	units[numUnits++] = newUnit;

	return true;
}

bool Level::placeWater(Point position, Point direction) {

	// check if can place water here
	water[numWater++] = Water(position, direction);

	return true;
}