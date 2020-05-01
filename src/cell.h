#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include <string>
#include "observer.h"
#include "noticeinfo.h"
#include "chamber.h"
#include "subject.h"
#include "state.h"
#include "content.h"

class Cell :public Observer<NoticeInfo>,public Subject<NoticeInfo>{
	string symbol;
	int y,x;
	bool SecNedmove = false;
  	bool gold9_pickable;
public:
	Cell();
	Cell* relate = nullptr;
	Content* cont;
	int chamber = -1;
	bool Nedmove = false;
	//2019/4/4 
	
	Cell(int y, int x);
	int getX();
	int getY();
	void pickAble();
	char print();
	bool Move();
	void needMove();
    bool Attack() ;
	bool Place() ;
    bool Using(bool a) ;
	bool Moveable(bool a) ;
	void swapCell(Cell &a);
	void replace(string str);
	void notify(Subject<NoticeInfo> &whoFrom);
	void createContent(string str);
	void trigger(State&);
	~Cell();
};



#endif // CELL_H_INCLUDED





