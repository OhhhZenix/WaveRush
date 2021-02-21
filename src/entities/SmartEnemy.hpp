#pragma once

#include "Entity.hpp"

class SmartEnemy : public Entity
{
private:
    sf::Vector2f position;
    sf::Vector2f speed;
    sf::Vector2f size;
    sf::RectangleShape shape;

public:
    SmartEnemy();

    void process_update(const double deltaTime) override;

    void process_render(sf::RenderWindow *window) override;
};