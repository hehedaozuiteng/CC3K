#include "character.h"
#include "werewolf.h"
#include "vampire.h"
#include "goblin.h"
#include "troll.h"
#include "phoenix.h"
#include "merchant.h"
#include "dragon.h"
#include "orc.h"
#include "elf.h"
#include "human.h"
#include "dwarf.h"
#include "henry.h"
#include "max.h"
Character *Character::CreateCharacter(RaceType r)
{
	if (r == RaceType::Werewolf)
	{
		return new Werewolf();
	}
	else if (r == RaceType::Vampire)
	{
		return new Vampire();
	}
	else if (r == RaceType::Goblin)
	{
		return new Goblin();
	}
	else if (r == RaceType::Troll)
	{
		return new Troll();
	}
	else if (r == RaceType::Phoenix)
	{
		return new Phoenix();
	}
	else if (r == RaceType::Merchant)
	{
		return new Merchant();
	}
	else if (r == RaceType::Dragon)
	{
		return new Dragon();
	}
	else if (r == RaceType::Orc)
	{
		return new Orc();
	}
	else if (r == RaceType::Elf)
	{
		return new Elf();
	}
	else if (r == RaceType::Human)
	{
		return new Human();
	}
	else if (r == RaceType::Dwarf)
	{
		return new Dwarf();
	}
	else if (r == RaceType::Max)
	{
		return new Max();
	}
	else if (r == RaceType::Henry)
	{
		return new Henry();
	}
	return nullptr;
}

Character::~Character() {}
