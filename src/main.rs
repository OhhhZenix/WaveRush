pub mod components;
pub mod entity;
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
    world.register::<components::Velocity>();
    world.register::<components::Tag>();

    let mut db = DispatcherBuilder::new()
        .with(
            systems::rendering::RenderRectangle,
            "systems::rendering::RenderRectangle",
            &[],
        )
        .with(
            systems::PlayerMovement,
            "systems::PlayerMovement",
            &["systems::rendering::RenderRectangle"],
        )
        .with(
            systems::BasicEnemyMovement,
            "systems::BasicEnemyMovement",
            &["systems::rendering::RenderRectangle"],
        )
        .build();

    entity::Player::spawn(&mut world);
    entity::BasicEnemy::spawn(&mut world);

    loop {
        clear_background(GRAY);

        db.dispatch(&world);
        world.maintain();

        next_frame().await
    }
}
