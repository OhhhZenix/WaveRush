use crate::{components, scale_factor};
use macroquad::prelude::*;
use specs::prelude::*;

pub struct BasicEnemyMovement;

impl<'a> System<'a> for BasicEnemyMovement {
    type SystemData = (
        ReadStorage<'a, components::Tag>,
        ReadStorage<'a, components::Rectangle>,
        WriteStorage<'a, components::Position>,
        WriteStorage<'a, components::Velocity>,
    );

    fn run(&mut self, data: Self::SystemData) {
        let (tag, rect, mut pos, mut velocity) = data;
        for (tag, rect, pos, velocity) in (&tag, &rect, &mut pos, &mut velocity).join() {
            // checking if the entity is BasicEnemy
            if *tag != components::Tag::BasicEnemy {
                continue;
            }

            // movement
            pos.x += velocity.x * scale_factor() * get_frame_time();
            pos.y += velocity.y * scale_factor() * get_frame_time();

            // change direction
            if pos.x <= 0.0 || pos.x >= screen_width() - (rect.width * scale_factor()) {
                velocity.x *= -1.0;
            }

            if pos.y <= 0.0 || pos.y >= screen_height() - (rect.height * scale_factor()) {
                velocity.y *= -1.0;
            }

            // clamping
            pos.x = (0.0_f32).max(pos.x.min(screen_width() - (rect.width * scale_factor())));
            pos.y = (0.0_f32).max(pos.y.min(screen_height() - (rect.height * scale_factor())));
        }
    }
}
