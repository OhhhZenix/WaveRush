#include "GameHUD.hpp"

GameHUD game_hud_create()
{
    GameHUD hud;
    hud.score = 0;
    hud.level = 1;
    return hud;
}

void game_hud_process_data(GameHUD *hud, WindowSettings *settings, std::vector<BasicEnemy> &basicEnemies)
{
    hud->score++;

    if (pow(hud->level + 1, 5) <= hud->score)
    {
        hud->level += 1;
        basicEnemies.clear();
        basic_enemy_spawn(settings, basicEnemies, 2 * hud->level);
    }

    std::cout << "Level " << hud->level << " Score " << hud->score << "\n";
}