#include <vector>
#include "./Headers/Components/Command/PickCommand.h"

PickCommand::PickCommand() : Command()
{
}

PickCommand::~PickCommand()
{
}

int PickCommand::getName()
{
    return name_;
}

void PickCommand::setName(int name)
{
    name_ = name;
}

Event *PickCommand::execute()
{
    Event *event = new Event();

    event->setEventType(PICK_TILE);

    std::vector<int> actorNames = event->getActorNames();

    actorNames.push_back(name_);

    event->setActorNames(actorNames);

    return event;
}
