#include "tile.h"

Tile::Tile() {
	type = TerrainType::Tile;
}

TerrainType Tile::getType()
{
    return type;
}
