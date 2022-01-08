// disables console in release build
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

pub mod components;
pub mod entity;
pub mod systems;

use hecs::World;
use macroquad::prelude::{
    clear_background, is_key_pressed, next_frame, screen_height, screen_width, Conf, KeyCode, GRAY,
};

fn window_conf() -> Conf {
    Conf {
        window_title: "Wave Rush".to_string(),
        window_width: 1280,
        window_height: 720,
        window_resizable: false,
        ..Default::default()
    }
}

#[macroquad::main(window_conf)]
async fn main() {
    let mut world = World::new();

    entity::Player::spawn(&mut world);

    // for _ in 0..5 {
    entity::SmartEnemy::spawn(&mut world);
    // }

    for _ in 0..11 {
        entity::BasicEnemy::spawn(&mut world);
    }

    loop {
        clear_background(GRAY);

        if is_key_pressed(KeyCode::Escape) {
            break;
        }

        if screen_width() != 1.0 && screen_height() != 1.0 {
            systems::RenderSystem::run(&mut world);
            systems::BasicEnemySystem::run(&mut world);
            systems::SmartEnemySystem::run(&mut world);
            systems::PlayerSystem::run(&mut world);
            systems::ClampSystem::run(&mut world);
        }

        next_frame().await
    }
}
