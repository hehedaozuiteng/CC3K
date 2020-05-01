#ifndef CONTENT_H
#define CONTENT_H


#include "state.h"

class Content{
public:
	Content();
	virtual void angry();
	virtual int trigger();
	virtual void BePickAble();
	virtual int getHp();
	virtual int getAtk();
	virtual int getDef();
	virtual void setHp(int HP);
	virtual bool isPC();
	virtual bool getHostile();
	virtual RaceType getRaceType();
	virtual ~Content();
};
#endif

