#include "merchant.h"

Merchant::Merchant()
{
    this->hp = 30;
    this->atk = 70;
    this->def = 5;
    this->hostile = false;
    this->type = RaceType::Merchant;
}

bool Merchant::getHostile()
{
    return this->hostile;
}
/*
bool Merchant::needMove()
{
    return false;
}
*/
int Merchant::getHp()
{
    return this->hp;
}

int Merchant::getAtk()
{
    return this->atk;
}

int Merchant::getDef()
{
    return this->def;
}

RaceType Merchant::getRaceType()
{
    return this->type;
}

void Merchant::setHp(int HP) {
	this->hp = HP;
}


