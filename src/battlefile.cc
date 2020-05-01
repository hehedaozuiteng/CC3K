#include "battlefile.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

BattleFile::BattleFile() {};
BattleFile::~BattleFile() {}

void BattleFile::fight(Cell &ca, Cell &cb, State &state) {
	Content *a = ca.cont;
	Content *b = cb.cont;
	RaceType raceA = a->getRaceType();
	RaceType raceB = b->getRaceType();

	int defB = b->getDef();
	int hpB = b->getHp();
	int damage = 0;


	if (a->isPC()) {
		//make that monster canot move
		
		cb.Nedmove = false;
		int attA = state.Atk;

		damage = (int)ceil((100 / (100 + (double)defB)) * (double)attA);
		if (raceB == RaceType::Werewolf) { //ignore suit
			action += "you damaged Werewolf " + to_string(damage) + " points. ";

		}
		else if (raceB == RaceType::Vampire) {
			action += "you damaged Vampire " + to_string(damage) + " points. ";

		}
		else if (raceB == RaceType::Troll) {
			if (b->getHp() < 100)
				b->setHp(b->getHp() + 10);
			action += "you damaged Troll " + to_string(damage) + " points. remember he can cover himself. ";

		}
		else if (raceB == RaceType::Dragon) {
			action += "you damaged Dragon  " + to_string(damage) + " points. Your mother must not love you. ";

		}
		else if (raceB == RaceType::Goblin) {
			action += "you damaged Goblin " + to_string(damage) + " points. ";

		}
		else if (raceB == RaceType::Merchant) {
			state.attacked_Merchant = true;
			action += "you damaged Merchant " + to_string(damage) + " points, everyone hate you now. Why you do that ? ";

		}
		else if (raceB == RaceType::Phoenix) {
			action += "you damaged Phoenix  " + to_string(damage) + " points, killing this moving fake potion.";

		}
		else if (raceB == RaceType::Henry) {
			action += "you damaged a Prophet " + to_string(damage) + " points, Henry is angry.";

		}
		if (hpB <= damage)


		{
			compass--;
			action += "you slamed it.";

			if (raceB == RaceType::Merchant) {
				cb.replace("8");
			}
			else if (raceB == RaceType::Dragon) {
				cb.relate->pickAble();
				cb.relate->relate = nullptr;
				cb.relate = nullptr;
				cb.replace(".");
			}
			else if (compass < 0) {
				addgold(state);
				cb.replace("Compass");
				compass += 10000000;
			}
			else {
				addgold(state);
				cb.replace(".");
			}

		}
		else {
			hpB -= damage;
			b->setHp(hpB);
		}


	}
	else
	{
		srand(time(0));
		int miss = (rand() % 2);

		int attA = a->getAtk();
		defB = state.Def;
		hpB = state.HP;
		damage = (int)ceil((100 / (100 + (double)defB)) * (double)attA);
		if (miss == 0)
		{
			if (raceA == RaceType::Werewolf) { //ignore suit

				action += "You miss the attack from Werewolf. ";
			}
			else if (raceA == RaceType::Vampire) {

				action += "You miss the attack from Vampire. ";
			}
			else if (raceA == RaceType::Troll) {
				action += "You miss the attack from Troll. ";
			}
			else if (raceA == RaceType::Dragon) {
				if (a->getHostile()) {
					action += "You miss the attack from Dragon. ";
				}
				else {
					action += "A dragon just watching you. ";
				}
			}
			else if (raceA == RaceType::Goblin) {

				
				action += "You miss the attack from  Goblin. ";
				if (state.gold > 0) {
					state.gold--;
					action += "  Watching your pocket!!";
				}

			}
			else if (raceA == RaceType::Merchant) {
				if (state.attacked_Merchant) {

					
					action += "You miss the attack from Merchan, Luckily.";
				}
				else {
					action += "Merchant want you buy something, but he does not have that function.";
				}
			}
			else if (raceA == RaceType::Phoenix) {

				
				action += "You miss the attack from Phoenix. ";

			}
			else if (raceA == RaceType::Henry) {


				action += " Henry is watching you. ";

			}
		}
		else {
			if (raceA == RaceType::Werewolf) { //ignore suit

				action += "Werewolf damaged you " + to_string(damage) + " points. ";
			}
			else if (raceA == RaceType::Vampire) {

				if (state.suit) damage = ceil((double)damage / 2);
				a->setHp(a->getHp() + damage- 10);
				action += "Vampire damaged you " + to_string(damage) + " points. ";
			}
			else if (raceA == RaceType::Troll) {

				if (state.suit) damage = ceil((double)damage / 2);
				if (a->getHp() < 100)
					a->setHp(a->getHp() + 10);
				action += "Troll damaged you " + to_string(damage) + " points. ";
			}
			else if (raceA == RaceType::Dragon) {
				if (a->getHostile()) {

					if (state.suit) damage = ceil((double)damage / 2);
					action += "Dragon damaged you " + to_string(damage) + " points. ";
				}
				else {
					damage = 0;
				}
			}
			else if (raceA == RaceType::Goblin) {

				if (state.suit) damage = ceil((double)damage / 2);
				action += "Goblin damaged you " + to_string(damage) + " points. ";
				if (state.gold > 0) {
					state.gold--;
					action += "  Watching your pocket.";
				}

			}
			else if (raceA == RaceType::Merchant) {
				if (state.attacked_Merchant) {

					if (state.suit) damage = ceil((double)damage / 2);
					action += "Merchant damaged you " + to_string(damage) + " points, everyone hate you.";
				}
				else {
					damage = 0;
				}
			}
			else if (raceA == RaceType::Phoenix) {

				if (state.suit) damage = ceil((double)damage / 2);
				action += "Phoenix damaged you " + to_string(damage) + " points, this is not a moving potion. ";

			}
			else if (raceA == RaceType::Henry) {

				damage = 0;
				action += " Henry is watching you. ";

			}

			//deal the damage from monster

			if (hpB <= damage) {
				state.HP = 0;
				NoticeInfo info{ InfoType::EndGame,0,0,0 };
				setNotice(info);
				notifyObservers();
				action += "    You are die!!!!!!!!!";
			}
			else {
				hpB -= damage;
				state.HP = hpB;
			}
		}
	}
};

void BattleFile::addgold(State &state) {
	if (state.race == "Orc")
	{
		state.gold += 0.5;
	}
	else if (state.race == "Dwarf") {
		state.gold += 2;
	}
	else {

		state.gold += 1;
	}




}



