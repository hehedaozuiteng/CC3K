#include "content.h"


Content::Content() {};

void Content::angry(){}
int Content::trigger(){return -1;}
void Content::BePickAble() {};
bool Content::getHostile() { return false; }
int Content::getAtk() { return 0; }
int Content::getDef() { return 0; }
int Content::getHp() { return 0; }
void Content::setHp(int hp) {}
bool Content::isPC() { return false; }
RaceType Content::getRaceType()
{
	return RaceType::None;
}
;

Content::~Content() {};

