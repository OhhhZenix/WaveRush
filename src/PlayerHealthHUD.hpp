#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

struct PlayerHealthHUD
{
    uint32_t health;
    uint32_t maxHealth;
    sf::Text info;
    sf::RectangleShape healthBar;
    sf::RectangleShape overlayBar;
    sf::RectangleShape backgroundBar;
};

PlayerHealthHUD hud_create(sf::Font *font);
void hud_process_data(PlayerHealthHUD *hud);
void hud_process_render(sf::RenderWindow *window, PlayerHealthHUD *hud);