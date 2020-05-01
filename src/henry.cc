#include "henry.h"

Henry::Henry()
{
    this->hp = 5000;
    this->atk = 0;
    this->def = 0;
	this->hostile = true;
    this->type = RaceType::Henry;
}
bool Henry::getHostile()
{
	return this->hostile;
}

int Henry::getHp()
{
    return this->hp;
}

int Henry::getAtk()
{
    return this->atk;
}
int Henry::getDef()
{
    return this->def;
}

void Henry::setHp(int HP) {
	this->hp = HP;
}
RaceType Henry::getRaceType() {
    return this->type;
}



