#include "./Headers/Components/Events/Event.h"

Event::Event()
{
}

Event::~Event()
{
}

std::vector<Actor *> Event::getActors()
{
    return this->actors;
}


EventType Event::getEventType()
{
    return this->event;
}


void Event::setActors(std::vector<Actor *> actors)
{
    this->actors = actors;
}

void Event::setEventType(EventType eventType)
{
    this->event = eventType;
}