#ifndef __DWARF_H__
#define __DWARF_H__
#include "hero.h"

class Dwarf : public Hero
{
  public:
    Dwarf();
    int getHp() override;
    int getAtk() override;
    int getDef() override;
    void setHp(int hp) override;
    RaceType getRaceType() override;
};

#endif


