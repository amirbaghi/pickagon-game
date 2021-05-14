#include "./Headers/Components/Command/CommandStream.h"

CommandStream::CommandStream()
{
}

CommandStream::~CommandStream()
{
}

CommandStream *CommandStream::instance()
{
    static CommandStream *instance = new CommandStream();
    return instance;
}

void CommandStream::pushCommand(Command *command)
{
    commands_.push(command);
}

Command *CommandStream::popCommand()
{
    if (commands_.empty())
        return nullptr;

    auto command = commands_.front();
    commands_.pop();

    return command;
}