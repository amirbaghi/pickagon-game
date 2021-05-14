#include <vector>
#include "./Headers/Components/Command/MoveCommand.h"

MoveCommand::MoveCommand() : Command()
{
}

MoveCommand::~MoveCommand()
{
}

Direction MoveCommand::getDirection()
{
    return direction_;
}

void MoveCommand::setDirection(Direction direction)
{
    direction_ = direction;
}

Event *MoveCommand::execute()
{
    Event *event = new Event();

    switch (direction_)
    {
    case UP:
        event->setEventType(MOVE_CAMERA_UP);
        break;
    case DOWN:
        event->setEventType(MOVE_CAMERA_DOWN);
        break;
    case RIGHT:
        event->setEventType(MOVE_CAMERA_RIGHT);
        break;
    case LEFT:
        event->setEventType(MOVE_CAMERA_LEFT);
        break;
    default:
        break;
    }

    return event;
}
