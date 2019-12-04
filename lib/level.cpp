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
	int numWaterDirections = 0;
	Point waterDirections[8];

	Unit newUnit = Unit(unit, position, direction);

	// TODO: check if unit can be placed
	units[numUnits++] = newUnit;

	// add water that comes out of unit
	switch (unit) {
	case UnitType::truck:
		numWaterDirections = 3;
		if (direction.x) {
			waterDirections[0] = { direction.x, -1 };
			waterDirections[1] = { direction.x, 0 };
			waterDirections[2] = { direction.x, 1 };
		}
		else {
			waterDirections[0] = { -1, direction.y };
			waterDirections[1] = { 0, direction.y };
			waterDirections[2] = { 1, direction.y };
		}
		break;
	case UnitType::boat:
		numWaterDirections = 8;
		waterDirections[0] = { -1, 1 };
		waterDirections[1] = { 0, 1 };
		waterDirections[2] = { 1, 1 };
		waterDirections[3] = { 0, -1 };
		waterDirections[4] = { 1, 0 };
		waterDirections[5] = { -1, -1 };
		waterDirections[6] = { -1, 0 };
		waterDirections[7] = { 1, -1 };
		break;
	case UnitType::heli:
		numWaterDirections = 4;
		waterDirections[0] = { -1, -1 };
		waterDirections[1] = { -1, 1 };
		waterDirections[2] = { 1, -1 };
		waterDirections[3] = { 1, 1 };
		break;
	default:
		break;
	}

	for (int i = 0; i < numWaterDirections; i++)
		placeWater({ position.x + waterDirections[i].x, position.y + waterDirections[i].y }, waterDirections[i]);
	return true;
}

bool Level::placeWater(Point position, Point direction) {

	// check if can place water here
	//std::cout << position << " " << direction << std::endl;
	water[numWater++] = Water(position, direction);

	return true;
}

void Level::spreadWater() {
	int x, y;
	for (int i = 0; i < numWater; i++) {
		std::cout << water[i].position << std::endl;
		x = (int)water[i].position.x;
		y = (int)water[i].position.y;
		if (x >= 0 && x < numTiles.x && y >= 0 && y < numTiles.y) {
			tiles[x][y].tileType = TileType::water;
			water[i].position = water[i].position + water[i].direction;
		}
	}
}