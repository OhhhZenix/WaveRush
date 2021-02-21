#pragma once

#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "WindowSettings.hpp"
#include "PlayerHealthHUD.hpp"
#include "Player.hpp"
#include "BasicEnemy.hpp"

struct Game
{
    // Window settings
    WindowSettings settings;

    // Game settings
    PlayerHealthHUD playerHealthHUD;
    std::unordered_map<std::string, sf::Font> fonts;

    // Entities in the world
    Player player;
    std::vector<BasicEnemy> basicEnemies;
};
