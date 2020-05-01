#ifndef __TREASURE_H__
#define __TREASURE_H__
#include "event.h"

class Treasure : public Event
{
    int type;

  public:
  	int trigger();
    Treasure(int);
};

#endif

