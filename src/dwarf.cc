#include "dwarf.h"

Dwarf::Dwarf()
{
    this->hp = 100;
    this->atk = 20;
    this->def = 30;
    this->type = RaceType::Dwarf;
}
int Dwarf::getHp()
{
    return this->hp;
}

int Dwarf::getAtk()
{
    return this->atk;
}
int Dwarf::getDef()
{
    return this->def;
}

void Dwarf::setHp(int HP) {
	this->hp = HP;
}

RaceType Dwarf::getRaceType() {
    return this->type;
}

