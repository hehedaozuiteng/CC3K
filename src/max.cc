#include "max.h"

Max::Max()
{
    this->hp = 200;
    this->atk = 100;
    this->def = 100;
    this->type = RaceType::Max;
}
int Max::getHp()
{
    return this->hp;
}

int Max::getAtk()
{
    return this->atk;
}
int Max::getDef()
{
    return this->def;
}

void Max::setHp(int HP) {
	this->hp = HP;
}
RaceType Max::getRaceType() {
    return this->type;
}




