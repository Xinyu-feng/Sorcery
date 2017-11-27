#include "card.h"
#include "subject.h"
#include "state.h"

void Card::notify(Subject &whoFrom){
	State s = whoFrom.getState();
	runEffect(s.card, s.trigger);
}
