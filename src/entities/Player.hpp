#pragma once

#include "core/Game.hpp"
#include "Entity.hpp"

class Player : public Entity
{
private:
    sf::Vector2f position;
    sf::Vector2f speed;
    sf::Vector2f size;
    sf::RectangleShape shape;
    uint32_t speedLevel;

public:
    Player();

    void process_event(sf::Event *event) override;

    void process_update(const double deltaTime) override;

    void process_render(sf::RenderWindow *window) override;

    const sf::Vector2f &get_position() const;
};