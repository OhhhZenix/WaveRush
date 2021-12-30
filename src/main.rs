pub mod components;
pub mod entity;
pub mod systems;
pub mod utils;

use macroquad::prelude::*;
use specs::prelude::*;

pub const APP_NAME: &str = "Wave Rush";
pub const GAME_WIDTH: f32 = 640.0;
pub const GAME_HEIGHT: f32 = 360.0;

fn window_conf() -> Conf {
    Conf {
        window_title: APP_NAME.to_owned(),
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
    #[cfg(feature = "profile")]
    puffin::set_scopes_on(true);

    let mut world = World::new();
    world.register::<components::Position>();
    world.register::<components::Rectangle>();
    world.register::<components::Tag>();
    world.register::<components::Velocity>();

    let mut db = DispatcherBuilder::new()
        .with(
            systems::rendering::RenderRectangle,
            "systems::rendering::RenderRectangle",
            &[],
        )
        .with(systems::PlayerMovement, "systems::PlayerMovement", &[])
        .with(
            systems::BasicEnemyMovement,
            "systems::BasicEnemyMovement",
            &[],
        )
         .with(
            systems::SmartEnemyMovement,
            "systems::SmartEnemyMovement",
            &[],
        )
        .build();

    entity::Player::spawn(&mut world);

    for _ in 0..10 {
        entity::BasicEnemy::spawn(&mut world);
    }

    entity::SmartEnemy::spawn(&mut world);

    loop {
        #[cfg(feature = "profile")]
        {
            puffin::profile_scope!("Main Loop");
            puffin::GlobalProfiler::lock().new_frame();
        }

        clear_background(GRAY);

        #[cfg(feature = "profile")]
        egui_macroquad::ui(|egui_ctx| {
            puffin_egui::profiler_window(egui_ctx);
        });

        db.dispatch(&world);
        world.maintain();

        #[cfg(feature = "profile")]
        {
            puffin::profile_scope!("E-GUI Draw");
            egui_macroquad::draw();
        }

        if is_key_pressed(KeyCode::Escape) {
            break;
        }

        #[cfg(feature = "profile")]
        puffin::profile_scope!("Next Frame");

        next_frame().await
    }
}
