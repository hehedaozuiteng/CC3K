#ifndef __TILE_H__
#define __TILE_H__
#include "terrain.h"

class Tile : public Terrain {
public:

    Tile();
    TerrainType getType() override;
};

#endif

