CC = g++

CXXFLAGS = -std=c++14 -Werror=vla

DEPS = player.o deck.o main.o

%.o: %.cc %.h
	${CC} ${CXXFLAGS} -c $<

Sorcery: ${DEPS}
	${CC} ${CXXFLAGS} ${DEPS} -o Sorcery

clean:
	rm *.o
