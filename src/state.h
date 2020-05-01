#pragma once
#ifndef STATE_H
#define STATE_H
#include <string>
#include <vector>

using namespace std;

enum class RaceType {
	Werewolf, Vampire, Goblin, Troll,
	Phoenix, Merchant, Dragon,
	Orc, Elf, Human, Dwarf,None,Henry,Max
};

struct State
{
	string race ="";
	float gold = 0;
	int HP = 0;
	int Atk = 0;
	int Def = 0;
	int suitfloor = 0;
	string action = "";
	int MAXHP = 0;
	bool suit = false;
	bool attacked_Merchant = false;
	bool compass = false;
	vector<string> print();
};


#endif

