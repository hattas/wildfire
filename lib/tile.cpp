#include "tile.h"

Tile::Tile() {
	height = 0;
	tileType = TileType::grass;
}

Tile::Tile(float tHeight, TileType type) {
	height = tHeight;
	tileType = type;
}