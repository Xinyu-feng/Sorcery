#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>

class Observer;

class Subject {
	std::vector<std::shared_ptr<Observer>> observers;
public:
	void attach(std::shared_ptr<Observer>, int insert = -1);
	void detach(std::shared_ptr<Observer>);
	void replace(std::shared_ptr<Observer>, int index);
	void notifyObservers();
};

#endif
