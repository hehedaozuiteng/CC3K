#ifndef __HENRY_H__
#define __HENRY_H__
#include "enemy.h"

class Henry : public Enemy
{
public:
	Henry();
	bool getHostile() override;
	//bool needMove() override;
	int getHp() override;
	int getAtk() override;
	int getDef() override;
	void setHp(int hp) override;
	RaceType getRaceType() override;
};

#endif

