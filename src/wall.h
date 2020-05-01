#ifndef __WALL_H__
#define __WALL_H__
#include "terrain.h"

class Wall : public Terrain {
public:
    Wall();
    TerrainType getType() override;
};

#endif

