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
    if (event.getActorNames().front() == tile.getName())
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

void UnselectedState::render(Tile &tile)
{
    glPushMatrix();
    glTranslatef(tile.getPosition().x, tile.getPosition().y, tile.getPosition().z);
    glScalef(0.5, 0.5, 1.0);
    glLoadName(tile.getName());
    tile.getModel()->render(tile.getFrame());
    glPopMatrix();
}