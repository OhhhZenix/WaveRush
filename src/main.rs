pub mod ecs;
pub mod game;
pub mod scene;

use game::Game;
use macroquad::prelude::*;
use scene::{play_scene::PlayScene, Scene};

pub struct Vec2<T> {
    x: T,
    y: T,
}

pub struct UpdateArgs {
    pub dt: f32,
}

impl Default for UpdateArgs {
    fn default() -> Self {
        return Self {
            dt: get_frame_time(),
        };
    }
}

pub struct RenderArgs {
    pub scale: Vec2<f32>,
}

impl Default for RenderArgs {
    fn default() -> Self {
        return Self {
            scale: Vec2 {
                x: (screen_width() / RENDER_SIZE.x) as f32,
                y: (screen_height() / RENDER_SIZE.y) as f32,
            },
        };
    }
}

pub const RENDER_SIZE: Vec2<f32> = Vec2 {
    x: 640 as f32,
    y: 360 as f32,
};

fn window_conf() -> Conf {
    return Conf {
        window_title: "Wave Rush".to_owned(),
        window_width: 1280,
        window_height: 720,
        ..Default::default()
    };
}

#[macroquad::main(window_conf)]
async fn main() {
    // do some initilization
    let mut game = Game::new(PlayScene::new());

    // start main loop
    loop {
        // handle input & update logic
        game.get_scene().update(UpdateArgs::default());

        // clear frame
        clear_background(BLACK);

        // draw frame
        game.get_scene().render(RenderArgs::default());

        // swap buffer
        next_frame().await;
    }
}
