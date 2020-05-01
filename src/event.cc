#include "event.h"
#include "potion.h"
#include "treasure.h"
#include "stair.h"
#include "barrier.h"
#include "compass.h"
Event* Event::createEvent(EventType e, int type){
	if(e == EventType::Potion){
		return new Potion(type);
	}else if(e == EventType::Treasure){
		return new Treasure(type);
	}else if(e == EventType::Item){
		if(type == 0){
			return new Compass();
		}else{
			return new Barrier();
		}
	}else if(e == EventType::Stair){
		return new Stair();
	}
	return nullptr;
}

