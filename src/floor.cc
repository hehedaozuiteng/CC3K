
#ifndef CHAMBER_NUM
#define CHAMBER_NUM 5
#endif // CHAMBER_NUM

#ifndef ROW
#define ROW 25
#endif // ROW

#ifndef COL
#define COL 79
#endif // COL

#include "floor.h"
#include "noticeinfo.h"
#include "cell.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "chamber.h"
#include <string>
#include "state.h"
#include "content.h"

using namespace std;

Floor::Floor() {};

void Floor::reFreshState() {
	//tell the cell that pc is come to here
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cell[i][j].observers.pop_back();
			cell[i][j].attach(this);
		}
	}
	battle.observers.clear();
	battle.attach(this);
	NoticeInfo info{ InfoType::PCcome,1,1,1 };
	setNotice(info);
	cell[pcy][pcx].notify(*this);
	//I do not even know wtf of the pointer
	//there thousand of bugs trust me do not teach here
	// just know here is tell the pc come



	state.race = race;
	if (state.gold < 0) state.gold = 0;
	state.action = battle.action;
	if (state.action == "") state.action = " You are in a adventure.";
}

bool Floor::existCell(int i, int j) {// i is y , j is x

	if ((i < 0) ||
		(j < 0) ||
		(i >= ROW) ||
		(j >= COL)) {

		return false;
	}

	return true;
}

Floor::Floor(string filename, string race) :filename{filename},race{ race } { 
	floor_count = 0;
	before_stand.createContent(".");
	ifstream file{ filename };
	string input;
	int count = 0;
	srand(time(0));
	suit_floor = rand() % 5;
	vector <pair<int, int>> dragon;

	while (getline(file, input) && (count < ROW)) {
		vector <Cell> list;

		for (int i = 0; i < COL; i++) {
			Cell c = Cell(count, i);

			
			if (input.at(i) == 'c') {
				c.createContent("Compass");

			}
			else
			{
				c.createContent(input.substr(i, 1));
			}

			

			if (input.at(i) == '9') {
				pair <int, int> draHo;
				draHo.first = count;
				draHo.second = i;
				dragon.emplace_back(draHo);
			}
			
			list.emplace_back(c);

		}
		cell.emplace_back(list);
		
		++count;
	}

	for (auto &a : dragon) {
		int y = a.first;
		int x = a.second;
		spewnADra(y, x);

	}


	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (existCell(i - 1, j - 1)) {
				cell[i][j].attach(&cell[i - 1][j - 1]);
			}
			if (existCell(i - 1, j)) {
				cell[i][j].attach(&cell[i - 1][j]);
			}
			if (existCell(i - 1, j + 1)) {
				cell[i][j].attach(&cell[i - 1][j + 1]);
			}
			if (existCell(i, j + 1)) {
				cell[i][j].attach(&cell[i][j + 1]);
			}
			if (existCell(i + 1, j + 1)) {
				cell[i][j].attach(&cell[i + 1][j + 1]);
			}
			if (existCell(i + 1, j)) {
				cell[i][j].attach(&cell[i + 1][j]);
			}
			if (existCell(i + 1, j - 1)) {
				cell[i][j].attach(&cell[i + 1][j - 1]);
			}
			if (existCell(i, j - 1)) {
				cell[i][j].attach(&cell[i][j - 1]);
			}
			cell[i][j].attach(this);
		}
	}



	for (int i = 0; i < CHAMBER_NUM; i++) {
		chamber.push_back(Chamber(&pcx, &pcy, &stairx, &stairy));
	}



	findCham();
	state.action = "You just spwn in a strange place, enjoy";
	state.race = race;
	state.gold = 0;

	
	newFloor();
	state.MAXHP = cell[pcy][pcx].cont->getHp();
	state.HP = state.MAXHP;
	state.Atk = cell[pcy][pcx].cont->getAtk();
	state.Def = cell[pcy][pcx].cont->getDef();

};

bool Floor::spewnADra(int i, int j) {
	vector<Cell *> dir;
	whereMove(i, j, dir);
	if (dir.size() > 0) {
		srand(time(0));
		int go = (rand() % dir.size());
		dir[go]->replace("Dragon");
		dir[go]->relate = &cell[i][j];
		cell[i][j].relate = dir[go];
		return true;
	}
	cell[i][j].pickAble();
	return false;
}

void Floor::noticeNeighbor(int i, int j, NoticeInfo info) {

	setNotice(info);


	if (existCell(i - 1, j - 1)) {
		cell[i - 1][j - 1].notify(*this);
	}
	if (existCell(i - 1, j)) {
		cell[i - 1][j].notify(*this);
	}
	if (existCell(i - 1, j + 1)) {
		cell[i - 1][j + 1].notify(*this);
	}
	if (existCell(i, j + 1)) {
		cell[i][j + 1].notify(*this);
	}
	if (existCell(i + 1, j + 1)) {
		cell[i + 1][j + 1].notify(*this);
	}
	if (existCell(i + 1, j)) {
		cell[i + 1][j].notify(*this);
	}
	if (existCell(i + 1, j - 1)) {
		cell[i + 1][j - 1].notify(*this);
	}
	if (existCell(i, j - 1)) {
		cell[i][j - 1].notify(*this);
	}



}

void Floor::findCham() {
	int chamCout = 0;
	for (int i = 0; i < ROW; i++)
	{

		for (int j = 0; j < COL; j++)
		{

			if ((cell[i][j].chamber == -1) && (cell[i][j].Place())) {
				NoticeInfo info{ InfoType::FindCham ,chamCout };
				setNotice(info);
				cell[i][j].notify(*this);
				++chamCout;
			}
		}
	}

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{

			if (cell[i][j].chamber != -1) {
				chamber[cell[i][j].chamber].cell_vec.push_back(&(cell[i][j]));
			}
		}

	}

}





bool Floor::Move(string dir) {
	int x = pcx;
	int y = pcy;
	// bad code style, but i run out of time
	battle.action = "";
	// bad style
	//need change here change the true to character

	//here also need to change the 
	bool moved = false;


	if (dir == "no") {
		if (existCell(y - 1, x)) {
			if (cell[y - 1][x].Move()) {
				cell[y - 1][x].trigger(state);
				cell[y][x].swapCell(cell[y - 1][x]);
				cell[y][x].swapCell(before_stand);
				--pcy;
				moved = true;
			}
		}
	}
	else if (dir == "so") {
		if (existCell(y + 1, x)) {
			if (cell[y + 1][x].Move()) {
				cell[y + 1][x].trigger(state);
				cell[y][x].swapCell(cell[y + 1][x]);
				cell[y][x].swapCell(before_stand);
				++pcy;
				moved = true;
			}
		}
	}
	else if (dir == "ea") {
		if (existCell(y, x + 1)) {
			if (cell[y][x + 1].Move()) {
				cell[y][x + 1].trigger(state);
				cell[y][x + 1].swapCell(cell[y][x]);
				cell[y][x].swapCell(before_stand);
				++pcx;
				moved = true;
			}
		}
	}
	else if (dir == "we") {
		if (existCell(y, x - 1)) {
			if (cell[y][x - 1].Move()) {
				cell[y][x - 1].trigger(state);
				cell[y][x - 1].swapCell(cell[y][x]);
				cell[y][x].swapCell(before_stand);
				--pcx;
				moved = true;
			}
		}
	}
	else if (dir == "ne") {
		if (existCell(y - 1, x + 1)) {
			if (cell[y - 1][x + 1].Move()) {
				cell[y - 1][x + 1].trigger(state);
				cell[y][x].swapCell(cell[y - 1][x + 1]);
				cell[y][x].swapCell(before_stand);
				--pcy;
				++pcx;
				moved = true;
			}
		}
	}
	else if (dir == "nw") {
		if (existCell(y - 1, x - 1)) {
			if (cell[y - 1][x - 1].Move()) {
				cell[y - 1][x - 1].trigger(state);
				cell[y][x].swapCell(cell[y - 1][x - 1]);
				cell[y][x].swapCell(before_stand);
				--pcy;
				--pcx;
				moved = true;
			}
		}
	}
	else if (dir == "se") {
		if (existCell(y + 1, x + 1)) {
			if (cell[y + 1][x + 1].Move()) {
				cell[y + 1][x + 1].trigger(state);
				cell[y][x].swapCell(cell[y + 1][x + 1]);
				cell[y][x].swapCell(before_stand);
				++pcy;
				++pcx;
				moved = true;
			}
		}
	}
	else if (dir == "sw") {
		if (existCell(y + 1, x - 1)) {
			if (cell[y + 1][x - 1].Move()) {
				cell[y + 1][x - 1].trigger(state);
				cell[y][x].swapCell(cell[y + 1][x - 1]);
				cell[y][x].swapCell(before_stand);
				++pcy;
				--pcx;
				moved = true;
			}
		}
	}

	if (nextFloor) {
		if (floor_count < 5) {

			newFloor();
			state.action = "You went to next floor, this is floor " + to_string(floor_count) + " .";
		}
		else {
			NoticeInfo info{ InfoType::EndGame };
			setNotice(info);
			notifyObservers();
		}
	}
	else if (moved) {
		// before the monster move have to tell everything monster they
		// need move
		for (int i = 0; i < CHAMBER_NUM; i++) {
			chamber[i].newMove();

		}
		reFreshState();
		MonsterMove();
		
	}
	else {
		state.action = "you cannot move to there. ";

	}


	return moved;

}

//attack inputa dir, and character will attak the monster in that 
//direction if there is a monsterexist
//the monster that being attack will not move, but rest will move
//if no monster if will return false;

bool Floor::Attack(string dir) {
	int x = pcx;
	int y = pcy;

	// bad code style, but i run out of time
	battle.action = "";
	// bad stylew

	//need change here change the true to character

	//here need to add the info later

	bool  attacked = false;


	if (dir == "no") {
		if (existCell(y - 1, x)) {
			if (cell[y - 1][x].Attack()) {
				y -= 1;
				attacked = true;
			}
		}
	}
	else if (dir == "so") {
		if (existCell(y + 1, x)) {
			if (cell[y + 1][x].Attack()) {
				y++;
				attacked = true;
			}
		}
	}
	else if (dir == "ea") {
		if (existCell(y, x + 1)) {
			if (cell[y][x + 1].Attack()) {
				x++;
				attacked = true;
			}
		}
	}
	else if (dir == "we") {
		if (existCell(y, x - 1)) {
			if (cell[y][x - 1].Attack()) {
				x--;
				attacked = true;
			}
		}
	}
	else if (dir == "ne") {
		if (existCell(y - 1, x + 1)) {
			if (cell[y - 1][x + 1].Attack()) {
				y--;
				x++;
				attacked = true;
			}
		}
	}
	else if (dir == "nw") {
		if (existCell(y - 1, x - 1)) {
			if (cell[y - 1][x - 1].Attack()) {
				y--;
				x--;
				attacked = true;
			}
		}
	}
	else if (dir == "se") {
		if (existCell(y + 1, x + 1)) {
			if (cell[y + 1][x + 1].Attack()) {
				y++;
				x++;
				attacked = true;
			}
		}
	}
	else if (dir == "sw") {
		if (existCell(y + 1, x - 1)) {
			if (cell[y + 1][x - 1].Attack()) {
				y++;
				x--;
				attacked = true;
			}
		}
	}
	if (attacked) {
		// before the monster move have to tell everything monster they
		// need move
		for (int i = 0; i < CHAMBER_NUM; i++) {
			chamber[i].newMove();

		}
		battle.fight(cell[pcy][pcx], cell[y][x], state);
		//battle.fight make that monster cannot move
		MonsterMove();
		reFreshState();
	}
	else {

		state.action = "you cannot attack that .";
	}

	return false;

}


bool Floor::Using(string dir) {
	int x = pcx;
	int y = pcy;

	//need change here change the true to character

	//here need to add the info later



	if (dir == "no") {
		if (existCell(y - 1, x)) {
			if (cell[y - 1][x].Using(true)) {
				cell[y - 1][x].trigger(state);
				return true;
			}
		}
	}
	else if (dir == "so") {
		if (existCell(y + 1, x)) {
			if (cell[y + 1][x].Using(true)) {
				cell[y + 1][x].trigger(state);
				return true;
			}
		}
	}
	else if (dir == "ea") {
		if (existCell(y, x + 1)) {
			if (cell[y][x + 1].Using(true)) {
				cell[y][x + 1].trigger(state);
				return true;
			}
		}
	}
	else if (dir == "we") {
		if (existCell(y, x - 1)) {
			if (cell[y][x - 1].Using(true)) {
				cell[y][x - 1].trigger(state);
				return true;
			}
		}
	}
	else if (dir == "ne") {
		if (existCell(y - 1, x + 1)) {
			if (cell[y - 1][x + 1].Using(true)) {
				cell[y - 1][x + 1].trigger(state);
				return true;
			}
		}
	}
	else if (dir == "nw") {
		if (existCell(y - 1, x - 1)) {
			if (cell[y - 1][x - 1].Using(true)) {
				cell[y - 1][x - 1].trigger(state);
				return true;
			}
		}
	}
	else if (dir == "se") {
		if (existCell(y + 1, x + 1)) {
			if (cell[y + 1][x + 1].Using(true)) {
				cell[y + 1][x + 1].trigger(state);
				return true;
			}
		}
	}
	else if (dir == "sw") {
		if (existCell(y + 1, x - 1)) {
			if (cell[y + 1][x - 1].Using(true)) {
				cell[y + 1][x - 1].trigger(state);
				return true;
			}
		}
	}
	return false;

}

bool Floor::newFloor() {
	before_stand.replace(".");
	//refresh the stuff
	nextFloor = false;
	int gold = 10;
	int potion = 10;
	//add compass 
	srand(time(0));

        state.compass = false;
	//for make game easy, so every 9 monster spewn a compass;
	battle.compass = rand() % 10;
	
	if (floor_count > 0) {
		state.Atk = cell[pcy][pcx].cont->getAtk();
		state.Def = cell[pcy][pcx].cont->getDef();
	}
	
	
if(filename != "map.txt"){
	cell.clear();
	ifstream file{ filename };
	string input;
	int count = 0;
	vector <pair<int, int>> dragon;
	for(int i = 0;i < 25*floor_count;i++){
	getline(file, input);
	}
	 while (getline(file, input) && (count < ROW)) {
	vector <Cell> list;
		for (int i = 0; i < COL; i++) {
			Cell c = Cell(count, i);
			if (input.at(i) == 'c') {
				c.createContent("Compass");
			}
			else
			{
				c.createContent(input.substr(i, 1));
			}

			if (input.at(i) == '9') {
				pair <int, int> draHo;
				draHo.first = count;
				draHo.second = i;
				dragon.emplace_back(draHo);
			}
			if ((input.at(i) <='5')&&(input.at(i) >= '0')) potion--;
			if ((input.at(i) <='9')&&(input.at(i) >= '6')) gold--;
			
		list.emplace_back(c);

		}
		cell.emplace_back(list);
		++count;
	}
	for (auto &a : dragon) {
		int y = a.first;
		int x = a.second;
		spewnADra(y, x);
	}
	chamber.clear();
	findCham();
	for (int i = 0; i < CHAMBER_NUM; i++) {
		chamber[i].start = false;
		chamber[i].use_count = 0;
		chamber[i].pcx = &pcx;
		chamber[i].pcy = &pcy;
		chamber[i].stairx = &stairx;
		chamber[i].stairy = &stairy;
		
	}
}
	else {
	for (int i = 0; i < CHAMBER_NUM; i++) {
		chamber[i].start = false;
		chamber[i].use_count = 0;
		chamber[i].newFloor(&pcx, &pcy, &stairx, &stairy);
	}
	}
	// need to add renew PC state here
	++floor_count;
	//Cell temp;



	
	int cham = (rand() % CHAMBER_NUM);
	while (!chamber[cham].spwnPC(race)) {
		cham = (rand() % CHAMBER_NUM);

	};
	chamber[cham].start = true;



	cham = (rand() % CHAMBER_NUM);

	

	while (!chamber[cham].spwnStair()) {
		cham = (rand() % CHAMBER_NUM);
	}
	

	while (potion > 0) {
		cham = (rand() % CHAMBER_NUM);
		if (chamber[cham].spwnPotion()) {
			--potion;
		}
	}


	if (suit_floor > 0) {
		suit_floor--;
	}
	else {
		pair < bool, pair<int, int>> suitResult;
		suitResult = chamber[cham].spwnSuit();
		while (suitResult.first == false){
			
			cham = (rand() % CHAMBER_NUM);
			suitResult = chamber[cham].spwnSuit();
		} 
		spewnADra(suitResult.second.first,
			suitResult.second.second);

	}



	pair< bool, pair<bool, pair<int, int>>> result;
	//first is does gold horde spwen
	//scond is is spwn the dragon
	//last is coop

	
	while (gold > 0) {

		cham = (rand() % CHAMBER_NUM);
		result = chamber[cham].spwnGold();
		if (result.first == true) {
			if (result.second.first == true) {
				spewnADra(result.second.second.first,
					result.second.second.second);

			}
			gold--;

		}

	}


	int Monster = 20;


	while (Monster > 0) {
		cham = (rand() % CHAMBER_NUM);
		if (chamber[cham].spwnMonster()) {
			--Monster;
		}
	}

	return true;

}

void Floor::notify(Subject<NoticeInfo> &whoFrom) {

	NoticeInfo info = whoFrom.getNotice();
	if (info.info == InfoType::ReachStair)
	{
		nextFloor = true;
	}
	else if (info.info == InfoType::meet)
	{
		battle.fight(cell[info.y][info.x], cell[pcy][pcx], state);
	}
	else if (info.info == InfoType::EndGame) {
		setNotice(info);
		notifyObservers();
	}
	else if (info.info == InfoType::meetPotion) {
		setNotice(info);
		battle.action = " You find a unknow potion.";
	}
}

void Floor::MonsterMove() {

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (cell[i][j].Nedmove) {
				randomMove(i, j);
			}

		}

	}


};


void Floor::whereMove(int y, int x, vector<Cell *> &dir) {
	if (existCell(y - 1, x)) {
		if (cell[y - 1][x].Place()) {
			dir.push_back(&cell[y - 1][x]);
		}
	}
	if (existCell(y + 1, x)) {
		if (cell[y + 1][x].Place()) {

			dir.push_back(&cell[y + 1][x]);
		}
	}

	if (existCell(y, x + 1)) {
		if (cell[y][x + 1].Place()) {

			dir.push_back(&cell[y][x + 1]);
		}
	}

	if (existCell(y, x - 1)) {
		if (cell[y][x - 1].Place()) {

			dir.push_back(&cell[y][x - 1]);
		}
	}

	if (existCell(y - 1, x + 1)) {
		if (cell[y - 1][x + 1].Place()) {

			dir.push_back(&cell[y - 1][x + 1]);
		}
	}

	if (existCell(y - 1, x - 1)) {
		if (cell[y - 1][x - 1].Place()) {

			dir.push_back(&cell[y - 1][x - 1]);
		}
	}

	if (existCell(y + 1, x + 1)) {
		if (cell[y + 1][x + 1].Place()) {

			dir.push_back(&cell[y + 1][x + 1]);
		}
	}

	if (existCell(y + 1, x - 1)) {
		if (cell[y + 1][x - 1].Place()) {

			dir.push_back(&cell[y + 1][x - 1]);
		}
	}

}

void Floor::randomMove(int y, int x) {
	cell[y][x].Nedmove = false;
	vector<Cell *> dir;
	whereMove(y, x, dir);
	if (dir.size() > 0) {
		srand(time(0));
		int go = (rand() % dir.size());
		cell[y][x].swapCell(*dir[go]);


	}

}


/*
				   _ooOoo_
				  o8888888o
				  88" . "88
				  (| -_- |)
				  O\  =  /O
			   ____/`---'\____
			 .'  \\|     |//  `.
			/  \\|||  :  |||//  \
		   /  _||||| -:- |||||-  \
		   |   | \\\  -  /// |   |
		   | \_|  ''\---/''  |   |
		   \  .-\__  `-`  ___/-. /
		 ___`. .'  /--.--\  `. . __
	  ."" '<  `.___\_<|>_/___.'  >'"".
	 | | :  `- \`.;`\ _ /`;.`/ - ` : | |
	 \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
				   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			佛祖保佑       永无BUG
*/


