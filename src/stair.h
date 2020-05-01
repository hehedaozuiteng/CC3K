#ifndef __STAIR_H__
#define __STAIR_H__
#include "event.h"

class Stair : public Event
{
	int trigger(){return -1;}
};

#endif

