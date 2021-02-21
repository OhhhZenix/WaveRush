#pragma once

#include <SFML/Graphics.hpp>

#include "WindowSettings.hpp"
#include "Player.hpp"

struct SmartEnemy
{
    sf::Vector2f size;
    sf::Vector2f speed;
    sf::Vector2f position;
    sf::RectangleShape shape;
};

void smart_enemy_spawn(WindowSettings *settings, std::vector<SmartEnemy> &smartEnemies, uint32_t amount);
void smart_enemies_process_movement(std::vector<SmartEnemy> &smartEnemies, Player *player, WindowSettings *settings);
void smart_enemies_process_render(sf::RenderWindow *window, std::vector<SmartEnemy> &smartEnemies);