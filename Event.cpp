#include "./Headers/Components/Events/Event.h"

Event::Event()
{
}

Event::~Event()
{
}

std::vector<Actor *> Event::getActors()
{
    return this->actors_;
}


EventType Event::getEventType()
{
    return this->event_;
}


void Event::setActors(std::vector<Actor *> actors)
{
    this->actors_ = actors;
}

void Event::setEventType(EventType eventType)
{
    this->event_ = eventType;
}