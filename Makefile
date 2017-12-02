CC = g++

CXXFLAGS = -std=c++14 -Werror=vla

%.o: %.cc %.h
	${CC} ${CXXFLAGS} -c $@

Sorcery:
	${CC} ${CXXFLAGS} *.o -o Sorcery

clean:
	rm *.o
