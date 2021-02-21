#include "Player.hpp"

#include "core/Game.hpp"
#include "Utils.hpp"

double speedByLevel(uint32_t level)
{
    return 600 + ((level - 1) * 100);
}

Player::Player() : Entity(EntityType::Player)
{
    this->speedLevel = 1;
    this->size = sf::Vector2f(50, 50);
    this->speed = sf::Vector2f(600, 600);
    this->position = sf::Vector2f(Game::instance().get_settings()->width / 2, Game::instance().get_settings()->height / 2);
    this->shape.setSize(this->size);
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(5);
}

void Player::process_event(sf::Event *event)
{
    if (event->type == sf::Event::KeyReleased)
    {
        if (event->key.code == sf::Keyboard::LShift)
            this->speedLevel = clamp(1, 10, this->speedLevel + 1);
        if (event->key.code == sf::Keyboard::LControl)
            this->speedLevel = clamp(1, 10, this->speedLevel - 1);
    }
}

void Player::process_update(const double deltaTime)
{
    // Check for speed adjustment
    {
        double newSpeed = speedByLevel(this->speedLevel);
        this->speed = sf::Vector2f(newSpeed, newSpeed);
        std::cout << "speed level " << this->speedLevel << " speed " << this->speed.x << "," << this->speed.y << "\n";
    }

    // Check for player input for movement
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

const sf::Vector2f &Player::get_position() const
{
    return this->position;
}