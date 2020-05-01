#include "phoenix.h"

Phoenix::Phoenix()
{
    this->hp = 50;
    this->atk = 35;
    this->def = 20;
    this->hostile = true;
    this->type = RaceType::Phoenix;
}

bool Phoenix::getHostile()
{
    return this->hostile;
}
/*
bool Phoenix::needMove()
{
    return true;
}*/

int Phoenix::getHp()
{
    return this->hp;
}

int Phoenix::getAtk()
{
    return this->atk;
}

int Phoenix::getDef()
{
    return this->def;
}

RaceType Phoenix::getRaceType()
{
    return this->type;
}

void Phoenix::setHp(int HP) {
	this->hp = HP;
}

