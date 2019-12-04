#pragma once

enum class TileType {
	grass,
	water,
	fire
};

class Tile {
public:
	
	float height;
	TileType tileType;
	
	Tile();
	Tile(float height, TileType tileType);

};
