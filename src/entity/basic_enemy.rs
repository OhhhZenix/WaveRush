use ::rand::{thread_rng, Rng};
use macroquad::prelude::*;
use specs::prelude::*;

use crate::{GAME_HEIGHT, GAME_WIDTH, components};

const BASIC_ENEMY_WIDTH: f32 = 16.0;
const BASIC_ENEMY_HEIGHT: f32 = 16.0;
const BASIC_ENEMY_BASE_SPEED_X: f32 = 300.0;
const BASIC_ENEMY_BASE_SPEED_Y: f32 = 300.0;

pub struct BasicEnemy;

impl BasicEnemy {
    pub fn spawn(world: &mut World) -> Entity {
        let mut rng = thread_rng();

        let (pos_x, pos_y) = (
            rng.gen_range(0..((GAME_WIDTH - BASIC_ENEMY_WIDTH) as u32)),
            rng.gen_range(0..((GAME_HEIGHT - BASIC_ENEMY_HEIGHT) as u32)),
        );

        let velocity_x = {
            if rng.gen_range(1..100) < 50 {
                1.0_f32
            } else {
                -1.0_f32
            }
        };

        let velocity_y = {
            if rng.gen_range(1..100) > 50 {
                1.0_f32
            } else {
                -1.0_f32
            }
        };

        world
            .create_entity()
            .with(components::Tag::BasicEnemy)
            .with(components::Position {
                x: pos_x as f32,
                y: pos_y as f32,
            })
            .with(components::Rectangle {
                width: BASIC_ENEMY_WIDTH,
                height: BASIC_ENEMY_HEIGHT,
                color: BLUE,
            })
            .with(components::Velocity {
                x: velocity_x * BASIC_ENEMY_BASE_SPEED_X,
                y: velocity_y * BASIC_ENEMY_BASE_SPEED_Y,
            })
            .build()
    }
}
