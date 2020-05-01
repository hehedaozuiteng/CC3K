
#include "game.h"
#include <fstream>
#include <iostream>
#include <string>
#include "state.h"
using namespace std;

Game::Game() {};

Game::Game(string filename, string race) {

	if (!(race == "h" || race == "e" || race == "d" || race == "o"|| race == "!")) {
		race = "h";
	}
	if (race == "h") race = "Human";
	else if (race == "e") race = "Elf";
	else if (race == "d") race = "Dwarf";
	else if (race == "o") race = "Orc";
	else if (race == "!") race = "Max";

	endGame = false;
	floor.attach(this);
	floor = Floor(filename, race);


	if(!curse)cout << display();


};

string Game::display() {
	bool compass = floor.state.compass;
	string output = "";
	for (int i = 0; i < 25; i++) {
		
		for (int j = 0; j < 79; j++) {

			char chat = floor.cell[i][j].print();

			if ((!compass) && (chat == '\\')) {
				output+= '.';
			}
			else {
				output+= chat;
			}


		}
		output += '\n';
	}
	for (auto &s : floor.state.print()) {
		output += s+'\n';
	}
	return output;

}
void Game::restart(string filename, string race) {
	if (!(race == "h" || race == "e" || race == "d" || race == "o")) {
		race = "h";
	}
	if (race == "h") race = "Human";
	else if (race == "e") race = "Elf";
	else if (race == "d") race = "Dwarf";
	else if (race == "o") race = "Orc";
	endGame = false;
	floor.release();

	floor = Floor(filename, race);
	floor.attach(this);

	//renew pc info

	if((!curse))cout << display();
}


bool Game::Move(string dir) {
#ifdef  TEST 
	cout << "called move : " << dir << endl;
#endif //  TEST == 1

	//if you do not there is the bug why not try to ignored it
	floor.release();
	floor.attach(this);
	//if you do not know where is the bug why not try to ignored it


	if (floor.Move(dir)) {
		
	}
	else {
		
	if(curse){
		floor.state.action = 
		floor.state.action.substr(0,floor.state.action.length() - 25);
		Attack(dir);
	}
			
		
	}

	if ((endGame)&&(!curse)) {
		if (floor.state.race == "Human")floor.state.gold *= 1.5;
		cout << "Your goal : " << floor.state.gold << endl;
		return endGame;
	}
	if((endGame)&&(curse)){
		if (floor.state.race == "Human") goal = floor.state.gold * 1.5;
	else {goal = floor.state.gold; }
		return endGame;
	}

	if((!curse))cout << display();
	//state.printinfo();
	return endGame;
}


bool Game::Attack(string dir) {
#ifdef  TEST
	cout << "called attack : " << dir << endl;
#endif //  TEST == 1

	//if you do not there is the bug why not try to ignored it
	floor.release();
	floor.attach(this);
	//if you do not know where is the bug why not try to ignored it


	if (floor.Attack(dir))
	{//success attack;
		

	}
	else {
			
	if(curse){
		floor.state.action = 
		floor.state.action.substr(0,floor.state.action.length() - 25);
		Using(dir);
	}
		
	}
	if((endGame)&&(!curse)) {
		if (floor.state.race == "Human")floor.state.gold *= 1.5;
		cout << "Your goal : " << floor.state.gold << endl;
		return endGame;
	}
	if((endGame)&&(curse)){
		if (floor.state.race == "Human") goal = floor.state.gold * 1.5;
		else {goal = floor.state.gold; }
		return endGame;
	}
	
	if((!curse))cout << display();
	//state.printinfo();

	return endGame;
}

bool Game::Using(string dir) {
#ifdef  TEST
	cout << "called Using : " << dir << endl;
#endif //  TEST == 1

	//if you do not there is the bug why not try to ignored it
	floor.release();
	floor.attach(this);
	//if you do not know where is the bug why not try to ignored it


	if (floor.Using(dir))
	{//success Using;
		//floor.MonsterMove();
	}
	else {
		// not success Using;

	}
	if (endGame) {
		if (floor.state.race == "Human")floor.state.gold *= 1.5;
		cout << "Your goal : " << floor.state.gold << endl;
		return endGame;
	}
	if((endGame)&&(curse)){
		if (floor.state.race == "Human") goal = floor.state.gold * 1.5;
		else {goal = floor.state.gold; }
		return endGame;
	}

	if((!curse))cout << display();

	//state.printinfo();

	return endGame;
}

void Game::notify(Subject<NoticeInfo> &whoFrom) {

	NoticeInfo info = whoFrom.getNotice();
	if (info.info == InfoType::EndGame)
	{
		endGame = true;
	}

}


