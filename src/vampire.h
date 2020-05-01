#ifndef VAM_H
#define VAM_H
#include "enemy.h"

class Vampire : public Enemy
{
  public:
    Vampire();
    bool getHostile() override;
    //bool needMove() override;
    int getHp() override;
    int getAtk() override;
    int getDef() override;
    void setHp(int hp) override;
    RaceType getRaceType() override;
};

#endif


