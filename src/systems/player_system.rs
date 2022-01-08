use crate::components;
use hecs::World;
use macroquad::prelude::{get_frame_time, is_key_down, KeyCode};

const PLAYER_BASE_SPEED: f32 = 1000.0;

pub struct PlayerSystem;

impl PlayerSystem {
    pub fn run(world: &mut World) {
        for (_, (tag, position)) in
            world.query_mut::<(&components::Tag, &mut components::Position)>()
        {
            if *tag != components::Tag::Player {
                continue;
            }

            if is_key_down(KeyCode::Right) {
                position.value.x += PLAYER_BASE_SPEED * get_frame_time();
            }
            if is_key_down(KeyCode::Left) {
                position.value.x -= PLAYER_BASE_SPEED * get_frame_time();
            }
            if is_key_down(KeyCode::Down) {
                position.value.y += PLAYER_BASE_SPEED * get_frame_time();
            }
            if is_key_down(KeyCode::Up) {
                position.value.y -= PLAYER_BASE_SPEED * get_frame_time();
            }
        }
    }
}
