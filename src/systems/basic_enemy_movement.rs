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
        #[cfg(feature = "profile")]
        puffin::profile_scope!(stdext::function_name!());

        let (tag, rect, mut pos, mut velocity) = data;
        (&tag, &rect, &mut pos, &mut velocity)
            .join()
            .filter(|(tag, _, _, _)| **tag == components::Tag::BasicEnemy)
            .for_each(|(_, rect, pos, velocity)| {
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
