#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED
#include "content.h"
enum class EventType{Potion,Treasure, Item, Stair};

class Event : public Content{
public:
	virtual int trigger() = 0;
	static Event* createEvent(EventType e, int type);
};

#endif // EVENT_H_INCLUDED


