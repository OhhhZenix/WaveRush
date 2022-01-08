use crate::components;
use hecs::{Entity, World};
use macroquad::prelude::{load_texture, screen_height, screen_width, Vec2, WHITE};
use pollster::block_on;

const PLAYER_WIDTH: f32 = 48.0;
const PLAYER_HEIGHT: f32 = 48.0;

pub struct Player;

impl Player {
    pub fn spawn(world: &mut World) -> Entity {
        world.spawn((
            components::Tag::Player,
            components::Position { value: Vec2::new(
                (screen_width() / 2.0) - PLAYER_WIDTH,
                (screen_height() / 2.0) - PLAYER_HEIGHT,
            ) },
            // components::Renderable::Rectangle {
            //     width: PLAYER_WIDTH,
            //     height: PLAYER_HEIGHT,
            //     color: Color::from_rgba(0, 255, 0, 255),
            // },
            components::Renderable::Sprite {
                texture: block_on(load_texture("assets/textures/player.png")).unwrap(),
                color: WHITE,
            },
        ))
    }
}
