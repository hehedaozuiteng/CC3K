#include "cell.h"
#include "character.h"
#include "event.h"
#include "terrain.h"
#include <string>
#include <iostream>
#include "state.h"
using namespace std;

int pt = -1;
 
Cell::Cell(){
	x=-1;
	y=-1;
}
Cell::Cell(int y, int x)
	: y(y), x(x), SecNedmove(false), gold9_pickable(false), cont(nullptr), Nedmove(false)
{}

int Cell::getX() {
	return x;
}




void Cell::trigger(State&s){
	//use
	if(symbol[0]=='G'){
		if (this->Move()) {

			float gold = (float)cont->trigger();
			if (s.race == "Dwarf") {
				s.gold += gold * 2;
			}
			else if (s.race == "Orc") {
				s.gold += gold / 2;
			}
			else {
				s.gold += gold;
			}
			s.action += " You pick the gold.";
			replace(".");
		}
		else {
			s.action += " You cannot pick that yet, there is a dragon.";
		}
	
	}else if(symbol[0] == 'P'){
		int p = cont->trigger();
		int hp=0,atk=0,def=0;
		if(p == 0){
			hp = 10;
			s.action += " You used a heal posion. ";
		}else if(p == 1){
			atk=5;
			s.action += " You used a attack posion. ";
		}else if(p == 2){
			def=5;
			s.action += " You used a defance posion. ";
		}else if(p == 3){
			hp = -10;
			s.action += " You take a posiion. ";
		}else if(p == 4){
			atk = -5;
			s.action += " You get nerfed. ";
		}else if(p == 5){
			def = -5;
			s.action += " You become weak. ";
		} 
		if(s.race == "Elf"){
			hp = abs(hp);
			atk= abs(atk);
			def = abs(def);
		}
		s.HP +=hp;
		s.Atk+=atk;
		s.Def+=def;
		if(s.HP>s.MAXHP)s.HP = s.MAXHP;
		if(s.HP<0)s.HP = 0;
		if(s.Atk<0)s.Atk = 0;
		if(s.Def<0)s.Def = 0;
		replace(".");
	
	}else if(symbol[0] == 'C'){
		s.action += " You pick a compass, you find the stair";
		s.compass = true;
		replace(".");
	}else if(symbol[0] == 'B'){
		if (Move()) {
			s.action += " You pick a barrier suit, you be stronger";
			s.suit = true;
			replace(".");
		}
		else {
			s.action += " You have to beat the dragon first";
		}
	}else if(symbol == "\\"){
		NoticeInfo info{ InfoType::ReachStair,0,0,0 };
		setNotice(info);
		notifyObservers();
	}
}
int Cell::getY() {
	return y;
}
char Cell::print() {
	return symbol[0];
}
void Cell::pickAble(){
	gold9_pickable = true;
}

bool Cell::Move() {
	if(symbol == "G"){

		if(cont->trigger()!=6){
			return true;
		}else if(gold9_pickable){
			return true;
		}else{
			return false;
		}
	}
	else if(symbol == "B"){
		return gold9_pickable;
	}else{
		return (symbol == "." || symbol == "+" || symbol == "#" || symbol == "C" || symbol == "\\");
	}
}
void Cell::needMove() {
	Nedmove = SecNedmove;
}
bool Cell::Attack() {
	if (cont) return (cont->getRaceType() != RaceType::None);
		return false;
}
bool Cell::Place() {
	return symbol[0] == '.';
}
bool Cell::Using(bool a) {
	return a;
}
bool Cell::Moveable(bool a) {
	return a;
}

void Cell::swapCell(Cell &a) {
	swap(SecNedmove, a.SecNedmove);
	swap(chamber, a.chamber);
	swap(Nedmove, a.Nedmove);
	swap(symbol, a.symbol);
	swap(cont, a.cont);
}
void Cell::replace(string str) {
	delete cont;
	createContent(str);
}


void Cell::notify(Subject<NoticeInfo> &whoFrom) {
	NoticeInfo info = whoFrom.getNotice();
	if ((Place()) && (chamber == -1) &&
		(info.info == InfoType::FindCham))
	{

		setNotice(info);
		chamber = info.chamber;
		notifyObservers();
	}else if (info.info == InfoType::PCreach) {
		if(cont){

			if (cont->getRaceType() != RaceType::None) {
				Nedmove = false;
				info.info = InfoType::meet;
				info.x = getX();
				info.y = getY();
				setNotice(info);
				notifyObservers();
			}else if (symbol == "P") {
				info.info = InfoType::meetPotion;
				info.x = getX();
				info.y = getY();
				setNotice(info);
				notifyObservers();
			}else if(symbol == "G"){
				int g = cont->trigger();
				if(g == 6){
					if(relate!=nullptr){
						relate->cont->angry();
					}
				}
			}
			else if (symbol == "B") {
					if (relate != nullptr) {
						relate->cont->angry();
					}
				
			}

		}
	}else if (info.info == InfoType::PCcome) {
		
			info.info = InfoType::PCreach;
			info.x = getX();
			info.y = getY();
			setNotice(info);
			notifyObservers();
		
	}
}

void Cell::createContent(string str)
{
	//cout<<"createContent"<<endl;
//	cout<<str<<endl;
//	cout<<str<<endl;
	if (str == "Vampire")
	{
		symbol = "V";
		Nedmove = true;
		cont = Character::CreateCharacter(RaceType::Vampire);
	}
	else if (str == "Werewolf")
	{
		symbol = "W";
		Nedmove = true;
		cont = Character::CreateCharacter(RaceType::Werewolf);
	}
	else if (str == "Henry")
	{
		symbol = "?";
		Nedmove = true;
		cont = Character::CreateCharacter(RaceType::Henry);
	}
	else if (str == "Goblin")
	{
		symbol = "N";
		Nedmove = true;
		cont = Character::CreateCharacter(RaceType::Goblin);
	}
	else if (str == "Troll")
	{
		symbol = "T";
		Nedmove = true;
		cont = Character::CreateCharacter(RaceType::Troll);
	}
	else if (str == "Phoenix")
	{
		symbol = "X";
		Nedmove = true;
		cont = Character::CreateCharacter(RaceType::Phoenix);
	}
	else if (str == "Merchant")
	{
		Nedmove = true;
		symbol = "M";
		cont = Character::CreateCharacter(RaceType::Merchant);
	}
	else if (str == "Dragon")
	{
		symbol = "D";
		cont = Character::CreateCharacter(RaceType::Dragon);
	}
	else if (str == "Orc")
	{
		symbol = "@";
		cont = Character::CreateCharacter(RaceType::Orc);
	}
	else if (str == "Elf")
	{
		symbol = "@";
		cont = Character::CreateCharacter(RaceType::Elf);
	}
	else if (str == "Human")
	{
		symbol = "@";
		cont = Character::CreateCharacter(RaceType::Human);
	}
	else if (str == "Dwarf")
	{
		symbol = "@";
		cont = Character::CreateCharacter(RaceType::Dwarf);
	}
	else if (str == "Max")
	{
		symbol = "@";
		cont = Character::CreateCharacter(RaceType::Max);
	}
	else if (str[0] >= '0' && str[0] < '6')
	{
		symbol = "P";
		pt = str[0] - '0';
		cont = Event::createEvent(EventType::Potion, str[0] - '0');
	}
	else if (str[0] >= '6' && str[0] <= '9') {
		symbol = "G";
		int val = 0;
		if(str == "6"){
			val = 1;
		}else if(str == "7"){
			val = 2;
		}else if(str == "8"){
			val = 4;
		}else if(str == "9"){
			val = 6;
		}
		cont = Event::createEvent(EventType::Treasure, val);
	}
	else if (str == "Compass")
	{
		symbol = "C";
		cont = Event::createEvent(EventType::Item, 0);
	}
	else if (str == "Barrier")
	{
		symbol = "B";
		cont = Event::createEvent(EventType::Item, 1);
	}
	else if (str == "Stair")
	{
		symbol = "\\";
		cont = Event::createEvent(EventType::Stair, 0);
	}
	else if (str == "-" || str == "|")
	{
		symbol = str;
		cont = Terrain::createTerrain(TerrainType::Wall);
	}
	else if (str == "#")
	{
		symbol = str;
		cont = Terrain::createTerrain(TerrainType::Passage);
	}
	else if (str == ".")
	{
		symbol = str;
		cont = Terrain::createTerrain(TerrainType::Tile);
	}
	else if (str == "+")
	{
		symbol = str;
		cont = Terrain::createTerrain(TerrainType::Doorway);
	}
	else {
		symbol = str;
		cont = nullptr;
	}
	SecNedmove = Nedmove;
}
Cell::~Cell() {
	//delete cont;
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
			·ð×æ±£ÓÓ       ÓÀÎÞBUG
*/





