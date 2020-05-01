#ifndef __MAX_H__
#define __MAX_H__
#include "hero.h"

class Max: public Hero {
    public:
    Max();
    int getHp() override;
    int getAtk() override;
    int getDef() override;
    void setHp(int hp) override;
    RaceType getRaceType() override;
};

#endif


