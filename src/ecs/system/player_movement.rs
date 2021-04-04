use crate::{
    ecs::component::{
        position::Position,
        tag::{Tag, TagType},
    },
    UpdateArgs,
};
use macroquad::prelude::*;
use specs::prelude::*;

pub struct PlayerMovementSystem;

impl<'a> System<'a> for PlayerMovementSystem {
    type SystemData = (
        Read<'a, UpdateArgs>,
        WriteStorage<'a, Position>,
        ReadStorage<'a, Tag>,
    );

    fn run(&mut self, (update_args, mut pos, tag): Self::SystemData) {
        for (pos, tag) in (&mut pos, &tag).join() {
            if tag.0 != TagType::Player {
                return;
            }

            const SPEED: f32 = 600.0;
            if is_key_down(KeyCode::W) {
                pos.y -= SPEED * update_args.dt;
            }
            if is_key_down(KeyCode::S) {
                pos.y += SPEED * update_args.dt;
            }
            if is_key_down(KeyCode::A) {
                pos.x -= SPEED * update_args.dt;
            }
            if is_key_down(KeyCode::D) {
                pos.x += SPEED * update_args.dt;
            }
        }
    }
}
