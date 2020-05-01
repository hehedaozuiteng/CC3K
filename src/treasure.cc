#include "treasure.h"

Treasure::Treasure(int i)
{
    type = i;
}

int Treasure::trigger(){
	return type;
}

