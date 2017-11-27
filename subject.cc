#include "subject.h"

void Subject<InfoType, StateType>::attach(Observer *o) {
	observers.emplace_back(o);
}

void Subject::notifyObservers() {
	for (auto &ob : observers) ob->notify(*this);
}
