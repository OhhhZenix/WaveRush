#include "Player.hpp"

#include "Utils.hpp"

Player player_create(WindowSettings *settings)
{
    Player player;
    player.size = sf::Vector2f(50, 50);
    player.speed = sf::Vector2f(20, 20);
    player.position = sf::Vector2f(settings->width / 2, settings->height / 2);
    player.shape.setSize(player.size);
    player.shape.setFillColor(sf::Color::Green);
    player.shape.setOutlineColor(sf::Color::Black);
    player.shape.setOutlineThickness(5);
    return player;
}

void player_process_movement(Player *player, WindowSettings *settings)
{
    // Check player input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        player->position.y -= player->speed.y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player->position.y += player->speed.y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player->position.x -= player->speed.x;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player->position.x += player->speed.x;

    // Clamping player position
    player->position.x = clamp(0, settings->width - player->size.x, player->position.x);
    player->position.y = clamp(0, settings->height - player->size.y, player->position.y);

    // Changing player position
    player->shape.setPosition(player->position.x, player->position.y);
}

void player_process_collision(Player *player, std::vector<BasicEnemy> &basicEnemies, HealthHUD *hud)
{
    if (basicEnemies.empty())
        return;
    for (BasicEnemy &basicEnemy : basicEnemies)
    {
        if (player->shape.getGlobalBounds().intersects(basicEnemy.shape.getGlobalBounds()))
        {
            hud->health -= 1;
            hud->health = clamp(0, hud->maxHealth, hud->health);
        }
    }
}

void player_process_render(sf::RenderWindow *window, Player *player)
{
    window->draw(player->shape);
}