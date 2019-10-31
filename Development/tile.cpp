#include "tile.h"


/*Tile Constructor*/
tile::tile(float tHeight, int type) {
	height = tHeight;
	tileType = type;
	if (type == Fire) {
		burnLevel = 1; //fire all starts at the same stage
	}
	else {
		burnLevel = 0; //all other types should not be burnt to begin
	}

}


/*Tile Functions*/

//function to progress the burning of tiles by changing the level of intensity when called
void tile::burntile(void) {
	if (this->tileType == Fire) {
		if (this->burnLevel == low) {
			this->burnLevel == medium;
		}
		else if (this->burnLevel == medium) {
			this->burnLevel == high;
		}
		else if (this->burnLevel == high) {
			this->burnLevel == burnt;
		}
		else if (this->burnLevel == burnt) {
			//already burnt, nothing changes
		}
	}
	else if (this->tileType == Grass) {
		this->tileType == Fire; //change type to fire
		this->burnLevel == 1; //initialize burn level to 0
	}
	else {
		/*only fire and grass can burn*/
	}
};
