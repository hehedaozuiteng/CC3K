#include "elf.h"

Elf::Elf()
{
    this->hp = 140;
    this->atk = 30;
    this->def = 10;
    this->type = RaceType::Elf;
}
int Elf::getHp()
{
    return this->hp;
}

int Elf::getAtk()
{
    return this->atk;
}
int Elf::getDef()
{
    return this->def;
}

void Elf::setHp(int HP) {
	this->hp = HP;
}

RaceType Elf::getRaceType() {
    return this->type;
}

