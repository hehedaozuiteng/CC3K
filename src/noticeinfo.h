#pragma once
#ifndef NOTICEINFO_H
#define NOTICEINFO_H


enum class InfoType { PCcome,PCreach,meet,ReachStair, EndGame, ReachCompass,FindCham,meetPotion};

struct NoticeInfo {
	InfoType info;
	int chamber;
	int x;
	int y;
};


#endif // !NOTICEINFO_H

