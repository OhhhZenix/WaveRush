#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class BasicEnemy : public Entity
{
private:
    sf::Vector2f position;
    sf::Vector2f speed;
    sf::Vector2f size;
    sf::RectangleShape shape;

public:
    BasicEnemy();

    void process_update(const double deltaTime) override;

    void process_render(sf::RenderWindow *window) override;
};