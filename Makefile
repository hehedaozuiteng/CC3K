CXX = g++
CXXFLAGS = -std=c++14 -DTEST  -Wall  -g -MMD
EXEC = cc3k+ -lncurses 
OBJECTS = henry.o max.o hero.o battlefile.o state.o content.o game.o floor.o chamber.o  cc3k.o character.o doorway.o dragon.o enemy.o event.o goblin.o merchant.o passage.o phoenix.o  terrain.o tile.o troll.o vampire.o wall.o werewolf.o  orc.o elf.o human.o dwarf.o cell.o barrier.o compass.o potion.o stair.o treasure.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
