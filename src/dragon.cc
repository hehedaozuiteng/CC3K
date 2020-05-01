#include "dragon.h"

Dragon::Dragon()
{
    this->hp = 150;
    this->atk = 20;
    this->def = 20;
    this->hostile = false;
    this->type = RaceType::Dragon;
}

bool Dragon::getHostile()
{
    return this->hostile;
}
/*
bool Dragon::needMove()
{
    return false;
}
*/
int Dragon::getHp()
{
    return this->hp;
}

int Dragon::getAtk()
{
    return this->atk;
}

int Dragon::getDef()
{
    return this->def;
}

RaceType Dragon::getRaceType()
{
    return this->type;
}

void Dragon::setHp(int HP) {
	this->hp = HP;
}

