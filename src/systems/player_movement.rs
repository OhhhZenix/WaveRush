use crate::{components, scale_factor};
use macroquad::prelude::*;
use specs::prelude::*;

const PLAYER_BASE_SPEED: f32 = 600.0;

pub struct PlayerMovement;

impl<'a> System<'a> for PlayerMovement {
    type SystemData = (
        ReadStorage<'a, components::Tag>,
        ReadStorage<'a, components::Rectangle>,
        WriteStorage<'a, components::Position>,
    );

    fn run(&mut self, data: Self::SystemData) {
        let (tag, rect, mut pos) = data;
        for (tag, rect, pos) in (&tag, &rect, &mut pos).join() {
            // check if the entity is a player
            if *tag != components::Tag::Player {
                continue;
            }

            // input
            if is_key_down(KeyCode::Right) {
                pos.x += PLAYER_BASE_SPEED * scale_factor() * get_frame_time();
            }
            if is_key_down(KeyCode::Left) {
                pos.x -= PLAYER_BASE_SPEED * scale_factor() * get_frame_time();
            }
            if is_key_down(KeyCode::Down) {
                pos.y += PLAYER_BASE_SPEED * scale_factor() * get_frame_time();
            }
            if is_key_down(KeyCode::Up) {
                pos.y -= PLAYER_BASE_SPEED * scale_factor() * get_frame_time();
            }

            // clamping
            pos.x = (0.0_f32).max(pos.x.min(screen_width() - (rect.width * scale_factor())));
            pos.y = (0.0_f32).max(pos.y.min(screen_height() - (rect.height * scale_factor())));
        }
    }
}
