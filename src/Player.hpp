#pragma once

#include <SFML/Graphics.hpp>

#include "WindowSettings.hpp"
#include "BasicEnemy.hpp"
#include "HealthHUD.hpp"

struct Player
{
    sf::Vector2f size;
    sf::Vector2f position;
    sf::Vector2f speed;
    sf::RectangleShape shape;
};

Player player_create(WindowSettings *settings);
void player_process_movement(Player *player, WindowSettings *settings);
void player_process_collision(Player *player, std::vector<BasicEnemy> &basicEnemies, HealthHUD *hud);
void player_process_render(sf::RenderWindow *window, Player *player);
