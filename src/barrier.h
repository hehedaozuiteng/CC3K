#ifndef __BARRIER_H__
#define __BARRIER_H__
#include "event.h"

class Barrier : public Event
{
	int trigger(){return -1;}
};

#endif



