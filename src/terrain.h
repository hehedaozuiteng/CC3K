#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED
#include "content.h"
enum class TerrainType{Wall, Passage, Tile, Doorway};

class Terrain: public Content{
protected:
	TerrainType type;
public:
	virtual TerrainType getType() = 0;
	static Terrain* createTerrain(TerrainType t);
};

#endif // TERRAIN_H_INCLUDED
