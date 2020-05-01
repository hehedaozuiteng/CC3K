#include "passage.h"

Passage::Passage() {
	type = TerrainType::Passage;
}

TerrainType Passage::getType()
{
    return type;
}
