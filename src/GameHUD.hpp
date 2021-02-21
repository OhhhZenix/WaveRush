#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "BasicEnemy.hpp"

struct GameHUD
{
    uint32_t score;
    uint32_t level;
    sf::Text scoreTxt;
    sf::Text levelTxt;
};

GameHUD game_hud_create();
void game_hud_process_data(GameHUD *hud, WindowSettings *settings, std::vector<BasicEnemy> &basicEnemies);