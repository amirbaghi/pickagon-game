#include "./Headers/Components/Subject.h"
#include "./Headers/Components/Events/Event.h"

void Subject::addObserver(Observer *observer)
{
    this->observers.push_back(observer);
}

void Subject::removeObserver(Observer *observer)
{
    for (auto it = observers.begin(); it != observers.end(); it++)
    {
        if (*it == observer)
        {
            this->observers.erase(it);
            return;
        }
    }
}

void Subject::notify(Event& event)
{
    for (auto it = observers.begin(); it != observers.end(); it++)
    {
        (*it)->onNotify(event);
    }
}
