#include "level.h"
#include "tile.h"
#include "point.h"

Unit::Unit() {
	type = UnitType::truck;
	position = { 0, 0 };
	size = { 1, 1 };
	direction = { 0, 0 };
}

Unit::Unit(UnitType type, Point position, Point direction) {
	this->type = type;
	this->position = position;
	this->direction = direction;
	switch (type) {
	case UnitType::truck:
		if (direction.x)
			size = { 3, 1 };
		else
			size = { 1, 3 };
		break;
	case UnitType::boat:
		if (direction.x)
			size = { 3, 1 };
		else
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

Water::Water(Point position, Point direction) {
	this->position = position;
	this->direction = direction;
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

bool Level::placeUnit(UnitType unit, Point position, Point direction) {
	Unit newUnit = Unit(unit, position, direction);

	// TODO: check if unit can be placed
	units[numUnits++] = newUnit;

	// add water that comes out of unit
	switch (unit) {
	case UnitType::truck:
		break;
	case UnitType::boat:
		
		break;
	case UnitType::heli:
		
		break;
	default:
		
		break;
	}

	return true;
}

bool Level::placeWater(Point position, Point direction) {

	// check if can place water here
	water[numWater++] = Water(position, direction);

	return true;
}