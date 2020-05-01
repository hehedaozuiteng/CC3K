#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include "character.h"
class Hero: public Character{
public:
	virtual RaceType getRaceType() = 0;
	bool getHostile() override; 
	bool isPC() override;
};


#endif // HERO_H_INCLUDED

