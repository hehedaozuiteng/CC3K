#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include "content.h"
#include "state.h"


class Character : public Content{
  protected:
    int hp, atk, def;
    RaceType type;
	
  public:
	
  	
    virtual ~Character() = 0;
    virtual void angry(){};
    static Character* CreateCharacter(RaceType r);
};

#endif

