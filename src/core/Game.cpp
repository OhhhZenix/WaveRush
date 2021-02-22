#include "Game.hpp"

#include <iostream>

Game::Game()
{
}

Game::~Game()
{
}

Game &Game::Instance()
{
    static Game s_Instance;
    return s_Instance;
}

void Game::Run()
{
    // Init
    {

    }

    // Loop
    {
    }
}

const WindowSettings *Game::GetSettings() const
{
    return &m_Settings;
}

void Game::ProcessEvent()
{
}

void Game::ProcessUpdate(const double p_DeltaTime)
{
}

void Game::ProcessRender()
{
}