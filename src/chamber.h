#ifndef CHAMBER_H_INCLUDED
#define CHAMBER_H_INCLUDED
#include "cell.h"
#include <vector>

using namespace std;
class Chamber{	
public:
	int *pcx;
	int *pcy;
	int *stairx;
	int *stairy;
	vector <Cell *> cell_vec;
	Chamber(int* pcx, int *pcy, int *stairx, int *stairy);
	Chamber();
	bool start = false;
	int use_count = 0;
	bool spwnPC(string race);
	bool setPC(Cell pc);
	pair< bool, pair<bool, pair<int, int>>> spwnGold();
	pair< bool, pair<int, int>> spwnSuit();
	bool spwnStair();
	bool spwnPotion();
	bool spwnMonster();
	void newMove();//refresh every cell who need move
	void newFloor(int* pcx, int *pcy, int *stairx, int *stairy);//refresh every cell to tiles 



};


#endif // CHAMBER_H_INCLUDED


