#include "SmartEnemy.hpp"

#include "Utils.hpp"

#define lerp(a, b, t) (a + (t * (b - a)))
#define sqr(x) (x * x)

void smart_enemy_spawn(WindowSettings *settings, std::vector<SmartEnemy> &smartEnemies, uint32_t amount)
{
    if (amount <= 0)
        return;
    for (int i = 0; i < amount; i++)
    {
        SmartEnemy smartEnemy;
        smartEnemy.size.x = 25;
        smartEnemy.size.y = 25;
        smartEnemy.speed.x = 0.025;
        smartEnemy.speed.y = 0.025;
        smartEnemy.position.x = random(0, settings->width - smartEnemy.size.x);
        smartEnemy.position.y = random(0, settings->height - smartEnemy.size.y);
        smartEnemy.shape.setSize(smartEnemy.size);
        smartEnemy.shape.setFillColor(sf::Color::Blue);
        smartEnemy.shape.setOutlineColor(sf::Color::Black);
        smartEnemy.shape.setOutlineThickness(3);
        smartEnemies.push_back(std::move(smartEnemy));
    }
}

void smart_enemies_process_movement(std::vector<SmartEnemy> &smartEnemies, Player *player, WindowSettings *settings)
{
    if (smartEnemies.empty())
        return;
    for (SmartEnemy &smartEnemy : smartEnemies)
    {
        float_t distance = sqrt(pow(player->position.x - smartEnemy.position.x, 2) + pow(player->position.y - smartEnemy.position.y, 2));
        std::cout << "first x " << pow(player->position.x - smartEnemy.position.x, 2) << " Second y " << pow(player->position.y - smartEnemy.position.y, 2) << "\n";
        smartEnemy.position.x = lerp(smartEnemy.position.x, player->position.x, smartEnemy.speed.x * distance);
        smartEnemy.position.y = lerp(smartEnemy.position.y, player->position.y, smartEnemy.speed.y * distance);
        smartEnemy.shape.setPosition(smartEnemy.position.x, smartEnemy.position.y);
        std::cout << "Distance: " << distance << "\n";
    }
}

void smart_enemies_process_render(sf::RenderWindow *window, std::vector<SmartEnemy> &smartEnemies)
{
    if (smartEnemies.empty())
        return;
    for (SmartEnemy &smartEnemy : smartEnemies)
    {
        window->draw(smartEnemy.shape);
    }
}