#include "potion.h"

Potion::Potion(int i)
{
    type = i;
}
int Potion::trigger(){
	return type;
}

