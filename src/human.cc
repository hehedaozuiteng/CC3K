#include "human.h"

Human::Human()
{
    this->hp = 140;
    this->atk = 20;
    this->def = 20;
    this->type = RaceType::Human;
}
int Human::getHp()
{
    return this->hp;
}

int Human::getAtk()
{
    return this->atk;
}
int Human::getDef()
{
    return this->def;
}

void Human::setHp(int HP) {
	this->hp = HP;
}
RaceType Human::getRaceType() {
    return this->type;
}

