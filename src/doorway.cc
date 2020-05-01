#include "doorway.h"

Doorway::Doorway()  {
	type = TerrainType::Doorway; 
}

TerrainType Doorway::getType()
{
    return type;
}


