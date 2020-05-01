#ifndef __POTION_H__
#define __POTION_H__
#include "event.h"

class Potion: public Event
{
    int type;
public:
	int trigger();
    Potion(int);
};


#endif

