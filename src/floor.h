

#ifndef FLOOR_H_INCLUDED
#define FLOOR_H_INCLUDED

#ifndef ROW
#define ROW 25
#endif // ROW

#ifndef COL
#define COL 79
#endif // COL

#include "cell.h"
#include "chamber.h"
#include "noticeinfo.h"
#include "subject.h"
#include "observer.h"
#include <fstream>
#include <vector>
#include <map>
#include "battlefile.h"

using namespace std;



class Floor:public Observer<NoticeInfo>, public Subject<NoticeInfo> {
	
	bool existCell(int i, int j);// i is y , j is xA
	bool nextFloor = false;
	void findCham();
	void randomMove(int i ,int j);
	void whereMove(int i, int j, vector<Cell *> &dir);
	void noticeNeighbor(int i, int j,NoticeInfo info);
	bool beAttack =false;
	int pcx;
	int pcy;
	int stairx;
	int stairy;
	int suit_floor = 0;
	int floor_count = 0;
	Cell before_stand = Cell(-1, -1);
	string filename = "map.txt";
	string race;
	BattleFile battle;
	void MonsterMove();
	void reFreshState();
	bool spewnADra(int i, int j);
public:
	vector<vector <Cell>> cell;
	vector<Chamber> chamber;
	State state;
	
	

	Floor();
	Floor(string filename, string race);
	bool Move(string dir);
	bool Attack(string dir);
	bool Using(string dir);
	
	bool newFloor();

	void notify(Subject<NoticeInfo> &whoFrom) override;




};


#endif // FLOOR_H_INCLUDED


