#ifndef __ORC_H__
#define __ORC_H__
#include "hero.h"

class Orc : public Hero
{
  public:
    Orc();
    int getHp() override;
    int getAtk() override;
    int getDef() override;
    void setHp(int hp) override;
    RaceType getRaceType() override;
};

#endif

