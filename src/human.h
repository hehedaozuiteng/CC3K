#ifndef __HUMAN_H__
#define __HUMAN_H__
#include "hero.h"

class Human : public Hero
{
  public:
    Human();
    int getHp() override;
    int getAtk() override;
    int getDef() override;
    void setHp(int hp) override;
    RaceType getRaceType() override;
};

#endif

