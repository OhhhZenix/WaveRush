#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "Utils.h"

struct WindowSettings
{
    std::string title = "WaveRush";
    uint32_t width = 1280;
    uint32_t height = 720;
};

struct Player
{
    uint32_t size;
    uint32_t speed;
    int32_t x;
    int32_t y;
    sf::RectangleShape shape;
};

struct BasicEnemy
{
    uint32_t size;
    uint32_t speedX;
    uint32_t speedY;
    int32_t x;
    int32_t y;
    sf::RectangleShape shape;
};

struct PlayerHealthHUD
{
    uint32_t health;
    uint32_t maxHealth;
    sf::RectangleShape healthBar;
    sf::RectangleShape backgroundBar;
};

struct Game
{
    // Window settings
    WindowSettings settings;

    // Game settings
    PlayerHealthHUD playerHealthHUD;

    // Entities in the world
    Player player;
    std::vector<BasicEnemy> basicEnemies;
};

void spawn_basic_enemy(Game *game, uint32_t amount)
{
    if (amount <= 0)
        return;
    for (int i = 0; i < amount; i++)
    {
        BasicEnemy basicEnemy;
        basicEnemy.size = 25;
        basicEnemy.speedX = 10;
        basicEnemy.speedY = 10;
        basicEnemy.x = random(0, game->settings.width);
        basicEnemy.y = random(0, game->settings.height);
        basicEnemy.shape.setSize(sf::Vector2f(basicEnemy.size, basicEnemy.size));
        basicEnemy.shape.setFillColor(sf::Color::Red);
        basicEnemy.shape.setOutlineColor(sf::Color::Black);
        basicEnemy.shape.setOutlineThickness(3);
        game->basicEnemies.push_back(std::move(basicEnemy));
    }
}

void init(Game *game)
{
    // Setup game setting
    game->playerHealthHUD.maxHealth = 100;
    game->playerHealthHUD.health = game->playerHealthHUD.maxHealth;
    game->playerHealthHUD.healthBar.setSize(sf::Vector2f(game->playerHealthHUD.health * 2, 50));
    game->playerHealthHUD.healthBar.setPosition(25, 25);
    game->playerHealthHUD.healthBar.setFillColor(sf::Color::Green);
    game->playerHealthHUD.backgroundBar.setSize(sf::Vector2f(game->playerHealthHUD.maxHealth * 2 + 12, 60));
    game->playerHealthHUD.backgroundBar.setPosition(20, 20);
    game->playerHealthHUD.backgroundBar.setFillColor(sf::Color::Black);

    // Setup player
    game->player.size = 50;
    game->player.speed = 20;
    game->player.x = game->settings.width / 2;
    game->player.y = game->settings.height / 2;
    game->player.shape.setSize(sf::Vector2f(game->player.size, game->player.size));
    game->player.shape.setFillColor(sf::Color::Green);
    game->player.shape.setOutlineColor(sf::Color::Black);
    game->player.shape.setOutlineThickness(5);

    spawn_basic_enemy(game, 5);
}

void process_events(sf::Event *event, sf::RenderWindow *window)
{
    if (event->type == sf::Event::Closed)
        window->close();
}

void process_player_collision(Game *game)
{
    for (BasicEnemy &basicEnemy : game->basicEnemies)
    {
        if (game->player.shape.getGlobalBounds().intersects(basicEnemy.shape.getGlobalBounds()))
        {
            game->playerHealthHUD.health -= 1;
            game->playerHealthHUD.health = clamp(0, game->playerHealthHUD.maxHealth, game->playerHealthHUD.health);
        }
    }
}

void process_update(Game *game)
{
    // Check player input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        game->player.y -= game->player.speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        game->player.y += game->player.speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        game->player.x -= game->player.speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        game->player.x += game->player.speed;

    // Clamping player position
    game->player.x = clamp(0, game->settings.width - game->player.size, game->player.x);
    game->player.y = clamp(0, game->settings.height - game->player.size, game->player.y);

    // Changing player position
    game->player.shape.setPosition(game->player.x, game->player.y);

    // Basic Enemies
    if (!game->basicEnemies.empty())
    {
        for (BasicEnemy &basicEnemy : game->basicEnemies)
        {
            // Basic enemies movement
            basicEnemy.x += basicEnemy.speedX;
            basicEnemy.y += basicEnemy.speedY;

            // Change direction for basic enemies
            if (basicEnemy.x <= 0 || basicEnemy.x >= game->settings.width - basicEnemy.size)
                basicEnemy.speedX *= -1;
            if (basicEnemy.y <= 0 || basicEnemy.y >= game->settings.height - basicEnemy.size)
                basicEnemy.speedY *= -1;

            // Changing basic enemies position
            basicEnemy.shape.setPosition(basicEnemy.x, basicEnemy.y);
        }
    }
}

void process_hud_render(sf::RenderWindow *window, Game *game)
{
    game->playerHealthHUD.healthBar.setSize(sf::Vector2f(game->playerHealthHUD.health * 2, 50));
    window->draw(game->playerHealthHUD.backgroundBar);
    window->draw(game->playerHealthHUD.healthBar);
}

void process_render(sf::RenderWindow *window, Game *game)
{
    window->draw(game->player.shape);

    if (!game->basicEnemies.empty())
    {
        for (BasicEnemy &basicEnemy : game->basicEnemies)
        {
            window->draw(basicEnemy.shape);
        }
    }

    process_hud_render(window, game);
}

void main()
{
    Game *game = new Game();
    sf::RenderWindow window(sf::VideoMode(game->settings.width, game->settings.height), game->settings.title);
    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f / 60.f);

    init(game);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            process_events(&event, &window);
        }

        while (accumulator > ups)
        {
            accumulator -= ups;
            process_update(game);
            process_player_collision(game);
        }

        window.clear(sf::Color(123, 86, 255));
        process_render(&window, game);
        window.display();

        accumulator += clock.restart();
    }
    delete game;
}