#include "./Headers/Components/Events/Event.h"

Event::Event()
{
}

Event::~Event()
{
}

std::vector<int> Event::getActorNames()
{
    return this->actorNames_;
}


EventType Event::getEventType()
{
    return this->event_;
}


void Event::setActorNames(std::vector<int> actorNames)
{
    this->actorNames_ = actorNames;
}

void Event::setEventType(EventType eventType)
{
    this->event_ = eventType;
}