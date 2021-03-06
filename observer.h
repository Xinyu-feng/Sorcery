#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Subject;
class State;

class Observer {
	public:
	virtual void notify(State s) = 0;
	virtual ~Observer() = default;
};
#endif
