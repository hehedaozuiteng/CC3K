#ifndef MERCHANT_H
#define MERCHANT_H
#include "character.h"
#include "enemy.h"

class Merchant : public Enemy
{
  public:
    Merchant();
    bool getHostile() override;
    //bool needMove() override;
    int getHp() override;
    int getAtk() override;
    int getDef() override;
    void setHp(int hp) override;
    RaceType getRaceType() override;
};

#endif


