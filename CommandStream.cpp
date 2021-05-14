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
    commands.push(command);
}

Command *CommandStream::popCommand()
{
    if (commands.empty())
        return nullptr;

    auto command = commands.front();
    commands.pop();

    return command;
}