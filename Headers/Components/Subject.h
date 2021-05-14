
#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "./Observer.h"
#include "./Events/Event.h"
#include "./Actor/Actor.h"

class Subject
{
public:
    // Method to add observer
    void addObserver(Observer *observer);

    // Method to remove Observer
    void removeObserver(Observer *observer);

protected:
    // Method to notify observers
    void notify(Event& event);

private:
    // Vector of Observers
    std::vector<Observer *> observers;
};

#endif