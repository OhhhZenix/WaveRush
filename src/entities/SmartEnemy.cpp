#include "SmartEnemy.hpp"

#include <iostream>
#include "core/Game.hpp"
#include "Player.hpp"
#include "Utils.hpp"

SmartEnemy::SmartEnemy() : Entity(EntityType::SmartEnemy)
{
    this->size = sf::Vector2f(25, 25);
    this->speed = sf::Vector2f(0.025, 0.025);
    this->position.x = random(0, Game::instance().get_settings()->width - this->size.x);
    this->position.y = random(0, Game::instance().get_settings()->height - this->size.y);
    this->shape.setSize(this->size);
    this->shape.setFillColor(sf::Color(153, 197, 209));
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(3);
}

void SmartEnemy::process_update(const double deltaTime)
{
    // Make enemy movement
    {
        // process for getting a player
        std::vector<Entity *> players = Game::instance().get_entity_manager().get_all_entity_with(EntityType::Player);
        int player_index = random(0, players.size() - 1);
        Player *player = (Player *)players[player_index];

        // distance between player and enemy
        float_t distance = sqrt(pow(player->get_position().x - this->position.x, 2) + pow(player->get_position().y - this->position.y, 2));

        // changing direction
        this->position.x = lerp(this->position.x, player->get_position().x, this->speed.x * distance * deltaTime);
        this->position.y = lerp(this->position.y, player->get_position().y, this->speed.y * distance * deltaTime);
        this->shape.setPosition(this->position.x, this->position.y);
    }
}

void SmartEnemy::process_render(sf::RenderWindow *window)
{
    window->draw(this->shape);
}