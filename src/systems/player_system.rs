use crate::{components, scale_factor};
use macroquad::prelude::*;
use specs::prelude::*;

pub struct PlayerSystem;

impl<'a> System<'a> for PlayerSystem {
    type SystemData = (
        WriteStorage<'a, components::Position>,
        ReadStorage<'a, components::Rectangle>,
    );

    fn run(&mut self, (mut pos, rect): Self::SystemData) {
        let speed = 600.0;
        for (pos, rect) in (&mut pos, &rect).join() {
            // input
            if is_key_down(KeyCode::Right) {
                pos.x += speed * scale_factor() * get_frame_time();
            }
            if is_key_down(KeyCode::Left) {
                pos.x -= speed * scale_factor() * get_frame_time();
            }
            if is_key_down(KeyCode::Down) {
                pos.y += speed * scale_factor() * get_frame_time();
            }
            if is_key_down(KeyCode::Up) {
                pos.y -= speed * scale_factor() * get_frame_time();
            }

            // clamping
            pos.x = (0.0 as f32).max(pos.x.min(screen_width() - (rect.width * scale_factor())));
            pos.y = (0.0 as f32).max(pos.y.min(screen_height() - (rect.height * scale_factor())));

            // rendering
            draw_rectangle(
                pos.x,
                pos.y,
                rect.width * scale_factor(),
                rect.height * scale_factor(),
                rect.color,
            );
        }
    }
}
