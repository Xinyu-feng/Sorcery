#include "subject.h"
#include "observer.h"

void Subject::attach(std::shared_ptr<Observer> o, int insert) {
    if (insert == -1 || insert >= observers.size()){
	    observers.emplace_back(o);
    }
    else{
        observers.insert(observers.begin() + insert, o);
    }
}

void Subject::detach(std::shared_ptr<Observer> o){
    for (auto it = observers.begin(); it != observers.end(); ++it){
        if (*it == o){
            observers.erase(it);
            break;
        }
    }
}

void Subject::replace(std::shared_ptr<Observer> o, int index){
    observers.at(index) = o;    
}


void Subject::notifyObservers() {
	for (auto &ob : observers) ob->notify(*this);
}
