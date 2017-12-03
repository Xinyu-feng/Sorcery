CXX=g++
CXXFLAGS=-std=c++14 -Wall -g -MMD -Werror=vla
OBJECTS = ascii_graphics.o board.o boardsubject.o card.o cardcollection.o deck.o effect.o enchant.o enchantment.o graphicsdisplay.o graveyard.o hand.o helper.o minion.o miniondecorator.o observer.o player.o ritual.o spell.o state.o subject.o window.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=sorcery

${EXEC}: ${OBJECTS} 
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC}
.PHONY: clean
