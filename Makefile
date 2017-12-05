CXX=g++
CXXFLAGS=-std=c++14 -Wall -g -MMD -Werror=vla
OBJECTS = ascii_graphics.o abilityminion.o basicminion.o board.o card.o deck.o enchant.o enchantment.o graphicsdisplay.o graveyard.o hand.o helper.o main.o minion.o miniondecorator.o player.o ritual.o spell.o triggerminion.o window.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=sorcery

${EXEC}: ${OBJECTS} 
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
