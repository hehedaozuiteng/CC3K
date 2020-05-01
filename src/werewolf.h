#ifndef WERE_H
#define WERE_H
#include "enemy.h"

class Werewolf : public Enemy
{
  public:
    Werewolf();
    bool getHostile() override;
    //bool needMove() override;
    int getHp() override;
    int getAtk() override;
    int getDef() override;
    void setHp(int hp) override;
    RaceType getRaceType() override;
};

#endif


