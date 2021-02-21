#pragma once

#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "WindowSettings.hpp"
#include "HealthHUD.hpp"
#include "Player.hpp"
#include "BasicEnemy.hpp"
#include "GameHUD.hpp"
#include "SmartEnemy.hpp"

struct Game
{
    // Window settings
    WindowSettings settings;

    // Game settings
    HealthHUD healthHUD;
    GameHUD gameHUD;
    std::unordered_map<std::string, sf::Font> fonts;

    // Entities in the world
    Player player;
    std::vector<BasicEnemy> basicEnemies;
    std::vector<SmartEnemy> smartEnemies;
};
