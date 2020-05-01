#include "troll.h"

Troll::Troll() {
 type = RaceType::Troll;
 hp = 120; 
 atk = 25;
 def = 15;
 hostile = true;
}

bool Troll::getHostile()
{
    return this->hostile;
}
/*
bool Troll::needMove()
{
    return true;
}
*/
int Troll::getHp()
{
    return this->hp;
}

int Troll::getAtk()
{
    return this->atk;
}

int Troll::getDef()
{
    return this->def;
}

RaceType Troll::getRaceType() {
    return this->type;
}

void Troll::setHp(int HP) {
	this->hp = HP;
}

