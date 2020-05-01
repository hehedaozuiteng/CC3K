#ifndef BATTLEFILE_H
#define  BATTLEFILE_H
#include "content.h"
#include "noticeinfo.h"
#include "subject.h"
#include "cell.h"
#include "state.h"
class BattleFile: public Subject<NoticeInfo>
{
public:
	int compass = 0;
	string action;
	void fight(Cell &a, Cell &b,State &state);
	void addgold(State &state);
	BattleFile(); 
	~BattleFile();



};

#endif // !BATTLEFILE_H


