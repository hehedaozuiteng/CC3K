
#include "chamber.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string> 
#include <iostream> 
using namespace std;

Chamber::Chamber() {};
Chamber::Chamber(int* pcx, int *pcy, int *stairx, int *stairy) : pcx{ pcx }, pcy{ pcy }, stairx{ stairx }, stairy{ stairy }{};


bool Chamber::spwnPC(string race) {
	if (!((size_t)use_count < cell_vec.size())) { 
		
		return false; }
	srand(time(0));
	int i = rand() % cell_vec.size();
	while (!(cell_vec[i]->Place()))
	{
		i = rand() % cell_vec.size();
	}
	++use_count;
	*pcx = cell_vec[i]->getX();
	*pcy = cell_vec[i]->getY();
	cell_vec[i]->replace(race);
	return true;
}

bool Chamber::setPC(Cell pc) {
	if (!((size_t)use_count < cell_vec.size())) return false;
	srand(time(0));
	int i = rand() % cell_vec.size();
	while (!(cell_vec[i]->Place()))
	{
		i = rand() % cell_vec.size();
	}
	++use_count;
	*pcx = cell_vec[i]->getX();
	*pcy = cell_vec[i]->getY();
	cell_vec[i]->swapCell(pc);
	return true;
}

bool Chamber::spwnStair() {
	if (start) return false;
	++use_count;
	srand(time(0));
	int i = rand() % cell_vec.size();
	while (!(cell_vec[i]->Place()))
	{
		i = rand() % cell_vec.size();
	}
	*stairx = cell_vec[i]->getX();
	*stairy = cell_vec[i]->getY();
	cell_vec[i]->replace("Stair");
	return true;
}

pair< bool, pair<int, int>> Chamber::spwnSuit() {
	pair< bool, pair<int, int>> ret;
	ret.first = false;
	if (!((size_t)use_count < cell_vec.size())) { return ret; }
	ret.first = true;
	srand(time(0));
	int i = rand() % cell_vec.size();
	while (!(cell_vec[i]->Place()))
	{
		i = rand() % cell_vec.size();
	}
	cell_vec[i]->replace("Barrier");


	ret.second.first = cell_vec[i]->getY();
	ret.second.second = cell_vec[i]->getX();

	++use_count;
	return ret;
}



pair< bool, pair<bool, pair<int, int>>> Chamber::spwnGold() {
	pair< bool, pair<bool, pair<int, int>>> ret;
	ret.first = false;
	if (!((size_t)use_count < cell_vec.size())) { return ret; }
	ret.first = true;
	srand(time(0));
	int i = rand() % cell_vec.size();
	while (!(cell_vec[i]->Place()))
	{
		i = rand() % cell_vec.size();
	}
	int type = (rand() % 8);
	//one more bad style, but I do not have time to make it beautiful
	if (type < 5)
		cell_vec[i]->replace("6");
	else if (type < 7)
		cell_vec[i]->replace("7");
	else
		cell_vec[i]->replace("9");



	if (type == 7)
	{
		ret.second.first = true;
		ret.second.second.first = cell_vec[i]->getY();
		ret.second.second.second = cell_vec[i]->getX();
	}
	++use_count;
	return ret;
}

bool Chamber::spwnPotion() {
	if (!((size_t)use_count < cell_vec.size())) return false;
	srand(time(0));
	int i = rand() % cell_vec.size();
	while (!(cell_vec[i]->Place()))
	{
		i = rand() % cell_vec.size();
	}
	int type = rand() % 6;
	cell_vec[i]->replace(to_string(type));

	++use_count;
	return true;
}



bool Chamber::spwnMonster() {

	if (!((size_t)use_count < cell_vec.size())) return false;
	int i = rand() % cell_vec.size();
	while (!(cell_vec[i]->Place()))
	{
		i = rand() % cell_vec.size();
	}
	int type = rand() % 19;
	/*

Werewolf: 2/9
• Vampire: 3/18
• Goblin: 5/18
• Troll: 1/9
• Phoenix: 1/9
• Merchant: 1/9


*/

// *cell_vec[rand() % cell_vec.size()] = monster Constructor(type);
	if (type < 4) { // 4/18 
		cell_vec[i]->replace("Werewolf");
	}
	else if (type < 7) { //7/18
		cell_vec[i]->replace("Vampire");
	}
	else if (type < 12) {
		cell_vec[i]->replace("Goblin");
	}
	else if (type < 14) {
		cell_vec[i]->replace("Troll");
	}
	else if (type < 16) {
		cell_vec[i]->replace("Phoenix");
	}
	else if(type < 17) {
		cell_vec[i]->replace("Merchant");
	}
	else
	{
		cell_vec[i]->replace("Henry");
	}

	++use_count;
	return true;
}

void Chamber::newMove() {
	for (size_t i = 0; i < cell_vec.size(); i++) {
		cell_vec[i]->needMove();

	}
}


void Chamber::newFloor(int* pcx, int *pcy, int *stairx, int *stairy) {
	use_count++;
	this->pcx = pcx;
	this->pcy = pcy;
	this->stairx = stairx;
	this->stairx = stairy;


	for (size_t i = 0; i < cell_vec.size(); i++)
	{
		cell_vec[i]->replace(".");
	}


}


