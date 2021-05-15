#include "./Headers/Components/State/SelectedState.h"
#include "./Headers/Components/State/UnselectedState.h"
#include "./Headers/Components/Events/Event.h"

SelectedState::SelectedState() : TileState()
{
}

SelectedState::~SelectedState()
{
}

TileState *SelectedState::handleEvent(Tile &tile, Event event)
{

    // If we want to pick another tile/unpick this tile
    // This tile should become unselected (?)
    if (event.getEventType() == PICK_TILE)
    {
        return new UnselectedState();
    }

    return nullptr;
}

void SelectedState::update(Tile &tile)
{
}

void SelectedState::render(Tile &tile)
{
    glPushMatrix();
    glTranslatef(tile.getPosition().x, tile.getPosition().y, tile.getPosition().z);
    glScalef(0.4, 0.4, 1.0);
    glLoadName(tile.getName());
    tile.getModel()->render(tile.getFrame());
    glPopMatrix();
}