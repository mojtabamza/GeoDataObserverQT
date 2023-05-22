#ifndef PATTERN_H
#define PATTERN_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Observer {
public:
    virtual void update(string& status) = 0;
private:
};

class Observable {
public:
    void attach(Observer& observer) {
        observers.push_back(&observer);
    }
    void detach(Observer& observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), &observer), observers.end());
    }
    void notify(string& status) {
        for(auto observer : observers) {
            observer->update(status);
        }
    }
private:
    vector<Observer*> observers;
};

#endif // PATTERN_H
