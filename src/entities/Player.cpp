#include "Player.hpp"

#include "core/Game.hpp"
#include "Utils.hpp"

Player::Player() : Entity(EntityID::Player)
{
    this->size = sf::Vector2f(50, 50);
    this->speed = sf::Vector2f(550, 550);
    this->position = sf::Vector2f(Game::instance().get_settings()->width / 2, Game::instance().get_settings()->height / 2);
    this->shape.setSize(this->size);
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(5);
}

void Player::process_update(const double deltaTime)
{
    // Check for player input
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            this->position.y -= this->speed.y * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            this->position.y += this->speed.y * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            this->position.x -= this->speed.x * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            this->position.x += this->speed.x * deltaTime;
    }

    // Clamping player position
    {
        this->position.x = clamp(0, Game::instance().get_settings()->width - this->size.x, this->position.x);
        this->position.y = clamp(0, Game::instance().get_settings()->height - this->size.y, this->position.y);
    }

    // Changing player position
    {
        this->shape.setPosition(this->position.x, this->position.y);
    }
}

void Player::process_render(sf::RenderWindow *window)
{
    window->draw(this->shape);
}