#include "./Headers/Components/Render/RenderEngine.h"
#include "./Headers/Game.h"

RenderEngine::RenderEngine()
{
}

RenderEngine::RenderEngine(Game *game)
{
    this->game = game;
}

RenderEngine::~RenderEngine()
{
}

RenderEngine *RenderEngine::instance(Game *game)
{
    static RenderEngine *instance = new RenderEngine(game);
    return instance;
}

void RenderEngine::render()
{
    // Render Logic Template
}