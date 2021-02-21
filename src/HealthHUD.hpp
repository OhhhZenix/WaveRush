#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

struct HealthHUD
{
    uint32_t health;
    uint32_t maxHealth;
    sf::Text info;
    sf::RectangleShape healthBar;
    sf::RectangleShape overlayBar;
    sf::RectangleShape backgroundBar;
};

HealthHUD health_hud_create(sf::Font *font);
void health_hud_process_data(HealthHUD *hud);
void health_hud_process_render(sf::RenderWindow *window, HealthHUD *hud);