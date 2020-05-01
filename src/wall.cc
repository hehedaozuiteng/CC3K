#include "wall.h"

Wall::Wall(){
	type = TerrainType::Wall;
}

TerrainType Wall::getType()
{
    return type;
}


