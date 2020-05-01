#ifndef GOB_H
#define GOB_H
#include "enemy.h"

class Goblin : public Enemy
{
  public:
    Goblin();
    bool getHostile() override;
    //bool needMove() override;
    int getHp() override;
    int getAtk() override;
    int getDef() override;
    void setHp(int hp) override;
    RaceType getRaceType() override;
};

#endif


