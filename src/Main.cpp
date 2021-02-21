#include "Game.hpp"

/*
- Allow adjustable speed for player
- Add particle system
- Add death system
- Add different types of enemies
- Parrying system
- Add a store
    - parrying
        - healing
        - split the enemies to double it
*/

void init(Game *game)
{
    game->fonts["Alphakind"] = sf::Font::Font();
    game->fonts["Alphakind"].loadFromFile("assets/fonts/Alphakind.ttf");
    game->settings = window_settings_create();
    game->healthHUD = health_hud_create(&game->fonts["Alphakind"]);
    game->gameHUD = game_hud_create();
    game->player = player_create(&game->settings);
    basic_enemy_spawn(&game->settings, game->basicEnemies, 1);
    smart_enemy_spawn(&game->settings, game->smartEnemies, 1);
}

void process_events(sf::Event *event, sf::RenderWindow *window)
{
    if (event->type == sf::Event::Closed)
        window->close();
}

void process_update(Game *game)
{
    player_process_movement(&game->player, &game->settings);
    basic_enemies_process_movement(game->basicEnemies, &game->settings);
    smart_enemies_process_movement(game->smartEnemies, &game->player, &game->settings);
    player_process_collision(&game->player, game->basicEnemies, &game->healthHUD);
    health_hud_process_data(&game->healthHUD);
    game_hud_process_data(&game->gameHUD, &game->settings, game->basicEnemies);
}

void process_render(sf::RenderWindow *window, Game *game)
{
    player_process_render(window, &game->player);
    basic_enemies_process_render(window, game->basicEnemies);
    smart_enemies_process_render(window, game->smartEnemies);
    health_hud_process_render(window, &game->healthHUD);
}

void main()
{
    Game *game = new Game();
    init(game);

    sf::RenderWindow window(sf::VideoMode(game->settings.width, game->settings.height), game->settings.title);
    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f / 60.f);

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
        }

        window.clear(sf::Color(123, 86, 255));
        process_render(&window, game);
        window.display();

        accumulator += clock.restart();
    }
    delete game;
}