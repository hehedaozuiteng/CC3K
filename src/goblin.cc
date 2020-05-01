#include "goblin.h"

Goblin::Goblin()
{
    this->hp = 70;
    this->atk = 5;
    this->def = 10;
    this->hostile = true;
    this->type = RaceType::Goblin;
}

bool Goblin::getHostile()
{
    return this->hostile;
}
/*
bool Goblin::needMove()
{
    return true;
}
*/
int Goblin::getHp()
{
    return this->hp;
}

int Goblin::getAtk()
{
    return this->atk;
}

int Goblin::getDef()
{
    return this->def;
}

RaceType Goblin::getRaceType()
{
    return this->type;
}

void Goblin::setHp(int HP) {
	this->hp = HP;

}


