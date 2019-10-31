enum tileType {
	Grass,
	Water,
	Fire
};

enum fireStrength {
	none,
	low,
	medium,
	high,
	burnt
};

class tile
{
public:
	/*Member Variables*/
	float height;
	int tileType;
	int burnLevel;
	/*constructor*/
	tile(float height, int tileType);
	/*Functions*/
	void burntile(void);
private:
	/*no private values*/
};

