#include "vampire.h"

Vampire::Vampire()
{
    this->hp = 50;
    this->atk = 25;
    this->def = 25;
    this->hostile = true;
    this->type = RaceType::Vampire;
}

bool Vampire::getHostile()
{
    return this->hostile;
}
/*
bool Vampire::needMove()
{
    return true;
}
*/
int Vampire::getHp()
{
    return this->hp;
}

int Vampire::getAtk()
{
    return this->atk;
}

int Vampire::getDef()
{
    return this->def;
}

RaceType Vampire::getRaceType()
{
    return this->type;
}

void Vampire::setHp(int HP) {
	this->hp = HP;
}

