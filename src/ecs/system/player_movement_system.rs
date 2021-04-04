use crate::{ecs::entity::player::Player, RENDER_HEIGHT, RENDER_WIDTH};
use amethyst::{
    core::{Time, Transform},
    derive::SystemDesc,
    ecs::{Join, Read, ReadStorage, System, SystemData, WriteStorage},
    input::{InputHandler, StringBindings},
    renderer::Sprite,
};
use num::clamp;

#[derive(SystemDesc)]
pub struct PlayerMovementSystem;

impl<'s> System<'s> for PlayerMovementSystem {
    type SystemData = (
        Read<'s, Time>,
        Read<'s, InputHandler<StringBindings>>,
        WriteStorage<'s, Player>,
        WriteStorage<'s, Transform>,
    );

    fn run(&mut self, (time, input, mut player, mut transform): Self::SystemData) {
        for (player, transform) in (&mut player, &mut transform).join() {
            const BASE_SPEED: f32 = 500.0;
            transform.prepend_translation_y(
                BASE_SPEED
                    * (player.speed_level) as f32
                    * input.axis_value("updown").unwrap_or_default()
                    * time.delta_seconds(),
            );
            transform.prepend_translation_x(
                BASE_SPEED
                    * (player.speed_level) as f32
                    * input.axis_value("leftright").unwrap_or_default()
                    * time.delta_seconds(),
            );
            transform.set_translation_x(clamp(
                transform.translation().x,
                16.0,
                RENDER_WIDTH - 16.0,
            ));
            transform.set_translation_y(clamp(
                transform.translation().y,
                16.0,
                RENDER_HEIGHT - 16.0,
            ));
        }
    }
}
