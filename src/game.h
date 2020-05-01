#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED


#include <string>
#include <fstream>
#include "floor.h"

#include "observer.h"

using namespace std;

class Game :public Observer<NoticeInfo> {
	
	Floor floor;
	bool endGame;
	
public:
	int goal = 0;
	bool curse = false;
	Game();
	Game(string filename, string race);
	string display();
	bool Move(string dir);
	bool Attack(string dir);
	bool Using(string dir);
	void restart(string filename, string race);
	void notify(Subject<NoticeInfo> &whoFrom) override;

};

#endif // GAME_H_INCLUDED

// return the false to restart the game which means the character will
// keep the gold


