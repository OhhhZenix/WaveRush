#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "WindowSettings.hpp"

struct BasicEnemy
{
    sf::Vector2f size;
    sf::Vector2f speed;
    sf::Vector2f position;
    sf::RectangleShape shape;
};

void basic_enemy_spawn(WindowSettings *settings, std::vector<BasicEnemy> &basicEnemies, uint32_t amount);
void basic_enemies_process_movement(std::vector<BasicEnemy> &basicEnemies, WindowSettings *settings);
void basic_enemies_process_render(sf::RenderWindow *window, std::vector<BasicEnemy> &basicEnemies);