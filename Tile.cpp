#include "./Headers/Components/Actor/Tile.h"
#include "./Headers/Components/State/UnselectedState.h"
#include "./Headers/Components/State/SelectedState.h"
#include "./Headers/Components/State/TileState.h"
#include "./Headers/Components/Events/Event.h"

Tile::Tile(Model *model, TileState *initialState) : Actor(model)
{
    // Set the initial state for the tile
    tileState_ = initialState;
}

Tile::~Tile()
{
    delete tileState_;
}

int Tile::getFrame()
{
    return frame;
}

void Tile::setFrame(int frame)
{
    this->frame = frame;
}

void Tile::onNotify(Event &event)
{
    // Handle the event
    TileState *newState = tileState_->handleEvent(*this, event);

    // If a new state was returned
    if (newState != nullptr)
    {
        // Delete the previous state
        delete tileState_;

        // Set the new state as the current state
        tileState_ = newState;

        // Enter the new state
        tileState_->enter(*this);
    }
}

vertex Tile::getPosition()
{
    return position_;
}

int Tile::getName()
{
    return name_;
}

void Tile::setPosition(vertex position)
{
    position_ = position;
}

void Tile::setName(int name)
{
    name_ = name;
}

void Tile::render()
{
    glPushMatrix();
    // glLoadIdentity();
    glTranslatef(position_.x, position_.y, position_.z);
    glScalef(0.5, 0.5, 1.0);
    glLoadName(name_);
    model->render(this->frame);
    glPopMatrix();
}