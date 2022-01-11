// disables console in release build
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

pub mod components;
pub mod entity;
pub mod systems;

use std::time::Instant;

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
    let start_time = Instant::now();
    let ticks_per_second = 60;
    let skip_ticks = 1000 / ticks_per_second;
    let max_frame_skip = 5;
    let mut next_game_tick = 0;
    let mut loops;
    let mut interpolation;
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

        loops = 0;
        while start_time.elapsed().as_millis() > next_game_tick && loops < max_frame_skip {
            if screen_width() != 1.0 && screen_height() != 1.0 {
                systems::BasicEnemySystem::run(&mut world);
                systems::SmartEnemySystem::run(&mut world);
                systems::PlayerSystem::run(&mut world);
                systems::ClampSystem::run(&mut world);
            }

            next_game_tick += skip_ticks;
            loops += 1;
        }

        interpolation = (start_time.elapsed().as_millis() as f64 + skip_ticks as f64
            - next_game_tick as f64)
            / (skip_ticks as f64);

        systems::RenderSystem::run(&mut world, interpolation);

        next_frame().await
    }
}
