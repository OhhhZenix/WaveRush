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
        #[cfg(feature = "profile")]
        puffin::profile_scope!(stdext::function_name!());

        let (tag, rect, mut pos) = data;
        (&tag, &rect, &mut pos)
            .join()
            .filter(|(tag, _, _)| **tag == components::Tag::Player)
            .for_each(|(_, rect, pos)| {
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
                pos.x = clamp(
                    pos.x.into(),
                    0.0,
                    (screen_width() - (rect.width * scale_factor())).into(),
                ) as f32;
                pos.y = clamp(
                    pos.y.into(),
                    0.0,
                    (screen_height() - (rect.height * scale_factor())).into(),
                ) as f32;
            });
    }
}
