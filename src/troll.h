#ifndef TROLL_H
#define TROLL_H
#include "enemy.h"

class Troll : public Enemy
{
  public:
    Troll();
    bool getHostile() override;
    //bool needMove() override;
    int getHp() override;
    int getAtk() override;
    int getDef() override;
    void setHp(int hp) override;
    RaceType getRaceType() override;
};

#endif


