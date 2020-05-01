#ifndef __PHOENIX_H__
#define __PHOENIX_H__
#include "enemy.h"

class Phoenix : public Enemy
{
  public:
    Phoenix();
    bool getHostile() override;
    //bool needMove() override;
    int getHp() override;
    int getAtk() override;
    int getDef() override;
    void setHp(int hp) override;
    RaceType getRaceType() override;
};

#endif


