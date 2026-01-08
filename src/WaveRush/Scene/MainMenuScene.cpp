#include "WaveRush/Scene/MainMenuScene.hpp"

#include <raylib.h>

#include "WaveRush/Constants.hpp"
#include "WaveRush/Entity/Bouncer.hpp"
#include "WaveRush/Game.hpp"
#include "WaveRush/Scene/PlayScene.hpp"
#include "WaveRush/Utils.hpp"
#include "WaveRush/Widget/Button.hpp"
#include "WaveRush/Widget/Label.hpp"

namespace WaveRush {

MainMenuScene::MainMenuScene() {
    auto w = 16.f;
    auto h = 16.f;
    for (int i = 0; i < 50; i++) {
        // generate color
        auto color = Color {
            GenerateRandomRange<unsigned char>(0, 255),
            GenerateRandomRange<unsigned char>(0, 255),
            GenerateRandomRange<unsigned char>(0, 255),
            255,
        };

        // generate speed
        auto speed_x = GenerateRandomRange(.5f, 2.f);
        auto speed_y = GenerateRandomRange(.5f, 2.f);

        // create entity
        auto& entity = this->entity_manager.AddEntity<Bouncer>();
        entity.SetX(GenerateRandomRange<float>(0 + w, GAME_WIDTH - w));
        entity.SetY(GenerateRandomRange<float>(0 + h, GAME_HEIGHT - h));
        entity.SetWidth(w);
        entity.SetHeight(h);
        entity.SetVelocityX(
            (GenerateRandomRange<int>(0, 1) ? -1.f : 1.f) * speed_x
        );
        entity.SetVelocityY(
            (GenerateRandomRange<int>(0, 1) ? -1.f : 1.f) * speed_y
        );
        entity.SetColor(color);
    }

    auto& game_title = widget_manager.AddWidget<Label>();
    game_title.SetText("Wave Rush");
    game_title.SetFontSize(48);
    game_title.SetColor(WHITE);
    game_title.SetX((GAME_WIDTH - (48 * 5)) / 2);
    game_title.SetY(40);

    auto button_gap = 20;
    auto button_width = 180;
    auto button_height = 60;
    auto button_count = 2;
    auto button_font_size = 24;

    auto& play_button = widget_manager.AddWidget<Button>();
    play_button.SetX((GAME_WIDTH - button_width) / 2);
    play_button.SetY((GAME_HEIGHT - (button_height * button_count)) / 2);
    play_button.SetWidth(button_width);
    play_button.SetHeight(button_height);
    play_button.SetOnClick([](Button& self, Game& game) {
        if (!self.IsLeftClicked())
            return;

        game.GetSceneManager().GotoNextScene(new PlayScene());
    });
    play_button.SetText("Play");
    play_button.SetFontSize(button_font_size);

    auto& exit_button = widget_manager.AddWidget<Button>();
    exit_button.SetX(play_button.GetX());
    exit_button.SetY(play_button.GetY() + play_button.GetHeight() + button_gap);
    exit_button.SetWidth(button_width);
    exit_button.SetHeight(button_height);
    exit_button.SetOnClick([](Button& self, Game& game) {
        if (!self.IsLeftClicked())
            return;

        game.Close();
    });
    exit_button.SetText("Quit");
    exit_button.SetFontSize(button_font_size);
}

auto MainMenuScene::Update(Game& game) -> void {
    this->entity_manager.Update(game);
    this->widget_manager.Update(game);
}

auto MainMenuScene::Render() -> void {
    this->entity_manager.Render();
    this->widget_manager.Render();
}

} // namespace WaveRush
