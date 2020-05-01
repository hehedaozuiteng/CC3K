#ifndef __PASSAGE_H__
#define __PASSAGE_H__
#include "terrain.h"

class Passage : public Terrain {
public:

    Passage();
    TerrainType getType() override;
};

#endif

