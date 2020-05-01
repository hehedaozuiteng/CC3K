#ifndef __ELF_H__
#define __ELF_H__
#include "hero.h"

class Elf : public Hero
{
  public:
    Elf();
    int getHp() override;
    int getAtk() override;
    int getDef() override;
    void setHp(int hp) override;
    RaceType getRaceType() override;
};

#endif

