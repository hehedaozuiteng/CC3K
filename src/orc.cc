#include "orc.h"

Orc::Orc(){
    this->hp = 180;
    this->atk = 30;
    this->def = 25;
    this->type = RaceType::Orc;
}
int Orc::getHp()
{
    return this->hp;
}

int Orc::getAtk()
{
    return this->atk;
}
int Orc::getDef()
{
    return this->def;
}

void Orc::setHp(int HP) {
	this->hp = HP;
}
RaceType Orc::getRaceType() {
    return this->type;
}

