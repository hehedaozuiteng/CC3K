#ifndef __COMPASS_H__
#define __COMPASS_H__
#include "event.h"

class Compass : public Event
{
	int trigger(){return -1;}
};

#endif

