#include "werewolf.h"

Werewolf::Werewolf()
{
    this->hp = 120;
    this->atk = 30;
    this->def = 5;
    this->hostile = true;
    this->type = RaceType::Werewolf;
}

bool Werewolf::getHostile()
{
    return this->hostile;
}
/*
bool Werewolf::needMove()
{
    return true;
}
*/
int Werewolf::getHp()
{
    return this->hp;
}

int Werewolf::getAtk()
{
    return this->atk;
}

int Werewolf::getDef()
{
    return this->def;
}

RaceType Werewolf::getRaceType()
{
    return this->type;
}

void Werewolf::setHp(int HP) {
	this->hp = HP;
}

