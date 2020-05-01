#include "state.h"


vector<string> State::print() {
	vector<string> ret;
	ret.emplace_back("Race : " + race + "  Gold : " + to_string(gold));
	ret.emplace_back("HP : "+to_string(HP));
	ret.emplace_back("Atk : " + to_string(Atk));
	ret.emplace_back("Def : " + to_string(Def));
    ret.emplace_back("action : " + action);
	return ret;
}

