#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "character.h"
#include "cell.h"
class Enemy : public Character
{
  protected:
    bool hostile;
  public:
    virtual void angry(){hostile = true;}
	virtual RaceType getRaceType() = 0;
  
};

#endif // ENEMY_H_INCLUDED


