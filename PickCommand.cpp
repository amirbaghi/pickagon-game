#include <vector>
#include "./Headers/Components/Command/PickCommand.h"

PickCommand::PickCommand() : Command()
{
}

PickCommand::~PickCommand()
{
}

Tile *PickCommand::getTile()
{
    return tile_;
}

void PickCommand::setTile(Tile *tile)
{
    tile_ = tile;
}

Event *PickCommand::execute()
{
    Event *event = new Event();

    event->setEventType(PICK_TILE);

    std::vector<Actor *> actors = event->getActors();

    actors.push_back(tile_);

    event->setActors(actors);

    return event;
}
