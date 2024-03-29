#include "level.h"
#include "tile.h"
#include "point.h"

const double tileChance = 0.04;
const double emberChance = 0.00001;

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

	// initialize 2d tile arrays
	Tile** tiles = new Tile * [(int)numTiles.x];
	for (int i = 0; i < numTiles.x; i++)
		tiles[i] = new Tile[(int)numTiles.y];
	this->tiles = tiles;

	Tile** tilesPrev = new Tile * [(int)numTiles.x];
	for (int i = 0; i < numTiles.x; i++)
		tilesPrev[i] = new Tile[(int)numTiles.y];
	this->tilesPrev = tiles;

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

bool Level::placeUnit(Unit unit) {
	placeUnit(unit.type, unit.position, unit.direction);
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

int Level::checkNeighboringTiles(int i, int j, int range) {
	int count = 0;
	for (int k = i - range; k <= i + range; k++) {
		if (k < 0 || k >= numTiles.x)
			continue;
		for (int l = j - range; l <= j + range; l++) {
			if (l < 0 || l >= numTiles.y || (i == k && j == l))
				continue;
			if (tilesPrev[k][l].tileType == TileType::fire) {
				count++;
			}
		}
	}
	return count;
}

void Level::removeUnitAtIndex(int index) {
	int i;
	for (int i = index; i < numUnits - 1; i++) {
		units[i] = units[i + 1];
	}
	numUnits--;
}

// removes unit at specified index
void Level::killUnit(Point firePos) {
	for (int u = 0; u < numUnits; u++) {
		if (units[u].position == firePos) {
			removeUnitAtIndex(u);
		}
	}
}

bool Level::moveUnit(int index, Point newPosition) {
	// move unit by adding new unit and deleting old one
	placeUnit(units[index].type, newPosition, units[index].direction);
	removeUnitAtIndex(index);
	return true;
}

void Level::spreadFire() {
	int numNeighbors, numNeighborsEmber;
	double chance, chanceEmber, r, rEmber;
	bool spread;

	// copy tiles to base fire spreading off previous state
	for (int i = 0; i < numTiles.x; i++) {
		for (int j = 0; j < numTiles.y; j++) {
			tilesPrev[i][j] = tiles[i][j];
		}
	}

	for (int i = 0; i < numTiles.x; i++) {
		for (int j = 0; j < numTiles.y; j++) {
			if (tilesPrev[i][j].tileType == TileType::fire)
				continue;
			numNeighbors = checkNeighboringTiles(i, j, 1);
			numNeighborsEmber = checkNeighboringTiles(i, j, 10);
			chance = tileChance * numNeighbors;
			chanceEmber = emberChance * numNeighborsEmber;
			r = (double)rand() / RAND_MAX;
			rEmber = (double)rand() / RAND_MAX;
			if ((r < chance || rEmber < chanceEmber) && tiles[i][j].tileType != TileType::water)
				spread = true;
			else
				spread = false;

			if (spread) {
				tiles[i][j].tileType = TileType::fire;
				killUnit({ (double)i, (double)j });
			}
		}
	}
}