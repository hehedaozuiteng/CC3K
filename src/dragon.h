#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"

class Dragon : public Enemy
{
  public:
    Dragon();
    bool getHostile() override;
    //bool needMove() override;
    int getHp() override;
    int getAtk() override;
    int getDef() override;
    void setHp(int hp) override;
    RaceType getRaceType() override;
};

#endif

