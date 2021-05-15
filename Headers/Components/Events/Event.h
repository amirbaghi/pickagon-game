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

    // Actor Names getter
    std::vector<int> getActorNames();
    // EventType Getter
    EventType getEventType();

    // Actors Setter
    void setActorNames(std::vector<int> actorNames);
    // EventType Setter
    void setEventType(EventType eventType);

private:
    // The names of the actors associated with this event
    std::vector<int> actorNames_;
    // The type of event
    EventType event_;
};

#endif