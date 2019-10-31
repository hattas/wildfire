#ifndef TILE_H
#define TILE_H

enum TileType {
	Grass,
	Water,
	Fire
};

enum FireStrength {
	none,
	low,
	medium,
	high,
	burnt
};

class Tile {
public:
	/* Member Variables */
	float height;
	TileType tileType;
	FireStrength burnLevel;

	/* constructor */
	Tile();
	Tile(float height, TileType tileType);

	/* Functions */
	void burnTile(void);

private:
	/* no private values */
};

#endif
