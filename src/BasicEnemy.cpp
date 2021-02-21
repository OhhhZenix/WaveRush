#include "BasicEnemy.hpp"

#include "Utils.hpp"

void basic_enemy_spawn(WindowSettings *settings, std::vector<BasicEnemy> &basicEnemies, uint32_t amount)
{
    if (amount <= 0)
        return;
    for (int i = 0; i < amount; i++)
    {
        BasicEnemy basicEnemy;
        basicEnemy.size.x = 25;
        basicEnemy.size.y = 25;
        basicEnemy.speed.x = 10;
        basicEnemy.speed.y = 10;
        basicEnemy.position.x = random(0, settings->width - basicEnemy.size.x);
        basicEnemy.position.y = random(0, settings->height - basicEnemy.size.y);
        basicEnemy.shape.setSize(basicEnemy.size);
        basicEnemy.shape.setFillColor(sf::Color::Red);
        basicEnemy.shape.setOutlineColor(sf::Color::Black);
        basicEnemy.shape.setOutlineThickness(3);
        basicEnemies.push_back(std::move(basicEnemy));
    }
}

void basic_enemies_process_movement(std::vector<BasicEnemy> &basicEnemies, WindowSettings *settings)
{
    if (basicEnemies.empty())
        return;
    for (BasicEnemy &basicEnemy : basicEnemies)
    {
        // Basic enemies movement
        basicEnemy.position.x += basicEnemy.speed.x;
        basicEnemy.position.y += basicEnemy.speed.y;

        // Change direction for basic enemies
        if (basicEnemy.position.x <= 0 || basicEnemy.position.x >= settings->width - basicEnemy.size.x)
            basicEnemy.speed.x *= -1;
        if (basicEnemy.position.y <= 0 || basicEnemy.position.y >= settings->height - basicEnemy.size.y)
            basicEnemy.speed.y *= -1;

        // Changing basic enemies position
        basicEnemy.shape.setPosition(basicEnemy.position.x, basicEnemy.position.y);
    }
}

void basic_enemies_process_render(sf::RenderWindow *window, std::vector<BasicEnemy> &basicEnemies)
{
    if (basicEnemies.empty())
        return;
    for (BasicEnemy &basicEnemy : basicEnemies)
    {
        window->draw(basicEnemy.shape);
    }
}