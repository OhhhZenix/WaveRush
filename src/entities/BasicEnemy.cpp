#include "BasicEnemy.hpp"

#include "core/Game.hpp"
#include "Utils.hpp"

BasicEnemy::BasicEnemy() : Entity(EntityType::BasicEnemy)
{
    this->size = sf::Vector2f(25, 25);
    this->speed = sf::Vector2f(700, 700);
    this->position.x = random(0, Game::instance().get_settings()->width - this->size.x);
    this->position.y = random(0, Game::instance().get_settings()->height - this->size.y);
    this->shape.setSize(this->size);
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(3);
}

void BasicEnemy::process_update(const double deltaTime)
{
    // Make the enemy move
    {
        this->position.x += this->speed.x * deltaTime;
        this->position.y += this->speed.y * deltaTime;
    }

    // Change direction
    {
        if (this->position.x <= 0 || this->position.x >= Game::instance().get_settings()->width - this->size.x)
            this->speed.x *= -1;
        if (this->position.y <= 0 || this->position.y >= Game::instance().get_settings()->height - this->size.y)
            this->speed.y *= -1;
    }

    // Changing the position
    {
        this->shape.setPosition(this->position.x, this->position.y);
    }
}

void BasicEnemy::process_render(sf::RenderWindow *window)
{
    window->draw(this->shape);
}