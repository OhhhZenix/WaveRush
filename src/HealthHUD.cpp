#include "HealthHUD.hpp"

HealthHUD health_hud_create(sf::Font *font)
{
    HealthHUD hud;
    hud.info.setFont(*font);
    hud.info.setCharacterSize(30);
    hud.info.setFillColor(sf::Color::White);
    hud.info.setStyle(sf::Text::Bold);
    hud.info.setPosition(sf::Vector2f(75, 35));
    hud.maxHealth = 100;
    hud.health = hud.maxHealth;
    hud.healthBar.setFillColor(sf::Color::Green);
    hud.healthBar.setPosition(30, 30);
    hud.overlayBar.setSize(sf::Vector2f(200, 50));
    hud.overlayBar.setPosition(30, 30);
    hud.overlayBar.setFillColor(sf::Color(84, 91, 102));
    hud.backgroundBar.setSize(sf::Vector2f(220, 70));
    hud.backgroundBar.setPosition(20, 20);
    hud.backgroundBar.setFillColor(sf::Color::Black);
    return hud;
}

void health_hud_process_data(HealthHUD *hud)
{
    hud->info.setString(std::string(std::to_string(hud->health) + "/" + std::to_string(hud->maxHealth)));
    hud->healthBar.setSize(sf::Vector2f(hud->health * 2, 50));
}

void health_hud_process_render(sf::RenderWindow *window, HealthHUD *hud)
{
    window->draw(hud->backgroundBar);
    window->draw(hud->overlayBar);
    window->draw(hud->healthBar);
    window->draw(hud->info);
}