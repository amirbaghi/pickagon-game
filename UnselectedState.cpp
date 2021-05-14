#include "./Headers/Components/State/SelectedState.h"
#include "./Headers/Components/State/UnselectedState.h"
#include "./Headers/Components/Events/Event.h"

UnselectedState::UnselectedState() : TileState()
{
}

UnselectedState::~UnselectedState()
{
}

TileState *UnselectedState::handleEvent(Tile &tile, Event event)
{

    // See if this event is related to this tile
    if (event.getActors().front() == &tile)
    {
        // If we want to pick this tile
        if (event.getEventType() == PICK_TILE)
        {
            return new SelectedState();
        }
    }

    return nullptr;
}

void UnselectedState::update(Tile &tile)
{
}