#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include "../Actor/Actor.h"
#include "./EventType.h"

class Event
{
public:
    Event();
    ~Event();

    // Actors getter
    std::vector<Actor *> getActors();
    // EventType Getter
    EventType getEventType();

    // Actors Setter
    void setActors(std::vector<Actor *> actors);
    // EventType Setter
    void setEventType(EventType eventType);

private:
    // The actors associated with the event
    std::vector<Actor *> actors;
    // The type of event
    EventType event;
};

#endif