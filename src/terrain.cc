#include "terrain.h"
#include "wall.h"
#include "passage.h"
#include "tile.h"
#include "doorway.h"

Terrain* Terrain::createTerrain(TerrainType t){
	if(t == TerrainType::Wall){
		return new Wall();
	}else if(t == TerrainType::Passage){
		return new Passage();
	}else if(t == TerrainType::Tile){
		return new Tile();
	}else if(t == TerrainType::Doorway){
		return new Doorway();
	}
	return nullptr;
}
