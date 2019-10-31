#include "tile.h"

Tile::Tile() {
	height = 0;
	tileType = Grass;
}

Tile::Tile(float tHeight, TileType type) {
	height = tHeight;
	tileType = type;
	if (type == Fire)
		burnLevel = low; // fire all starts at the same stage
	else
		burnLevel = none; // all other types should not be burnt to begin

}


/* Tile Functions */

// function to progress the burning of tiles by changing the level of intensity when called
void Tile::burnTile(void) {
	if (this->tileType == Fire) {
		if (this->burnLevel == low) {
			this->burnLevel = medium;
		}
		else if (this->burnLevel == medium) {
			this->burnLevel = high;
		}
		else if (this->burnLevel == high) {
			this->burnLevel = burnt;
		}
		else if (this->burnLevel == burnt) {
			// already burnt, nothing changes
		}
	}
	else if (this->tileType == Grass) {
		this->tileType = Fire; // change type to fire
		this->burnLevel = low; // initialize burn level to 0
	}
	else {
		/* only fire and grass can burn */
	}
};
