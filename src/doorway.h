#ifndef __DOORWAY_H__
#define __DOORWAY_H__
#include "terrain.h"

class Doorway : public Terrain {
public:

    Doorway();
    TerrainType getType() override;
};

#endif

