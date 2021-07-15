pub mod components;
pub mod systems;

use macroquad::prelude::*;
use specs::prelude::*;

pub const APP_NAME: &str = "Wave Rush";
pub const GAME_WIDTH: f32 = 640.0;
pub const GAME_HEIGHT: f32 = 360.0;

fn window_conf() -> Conf {
    Conf {
        window_title: "Wave Rush".to_owned(),
        window_width: 1280,
        window_height: 720,
        ..Default::default()
    }
}

pub fn scale_factor() -> f32 {
    // (screen_height() / GAME_HEIGHT).min(screen_width() / GAME_WIDTH)
    (screen_width() / GAME_WIDTH).min(screen_height() / GAME_HEIGHT)
}

#[macroquad::main(window_conf)]
async fn main() {
    let mut world = World::new();
    world.register::<components::Position>();
    world.register::<components::Rectangle>();

    let mut db = DispatcherBuilder::new()
        .with(systems::PlayerSystem, "PlayerSystem", &[])
        .build();

    world
        .create_entity()
        .with(components::Position {
            x: screen_width() / 2.0,
            y: screen_height() / 2.0,
        })
        .with(components::Rectangle {
            width: 32.0,
            height: 32.0,
            color: RED,
        })
        .build();

    loop {
        clear_background(GRAY);

        db.dispatch(&world);
        world.maintain();

        next_frame().await
    }
}
