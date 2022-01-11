// disables console in release build
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

pub mod components;
pub mod entity;
pub mod systems;

use hecs::World;
use macroquad::prelude::{
    clear_background, get_frame_time, is_key_pressed, next_frame, screen_height, screen_width,
    Conf, KeyCode, GRAY,
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
    let updates_per_second = 1.0 / 60.0;
    let mut accumulator = 0.0;
    let mut world = World::new();

    entity::Player::spawn(&mut world);
    entity::SmartEnemy::spawn(&mut world);

    for _ in 0..11 {
        entity::BasicEnemy::spawn(&mut world);
    }

    loop {
        clear_background(GRAY);

        if is_key_pressed(KeyCode::Escape) {
            break;
        }

        accumulator += get_frame_time();
        while accumulator > updates_per_second {
            if screen_width() != 1.0 && screen_height() != 1.0 {
                systems::BasicEnemySystem::run(&mut world);
                systems::SmartEnemySystem::run(&mut world);
                systems::PlayerSystem::run(&mut world);
                systems::ClampSystem::run(&mut world);
            }
            accumulator -= updates_per_second;
        }

        systems::RenderSystem::run(&mut world);

        next_frame().await
    }
}
