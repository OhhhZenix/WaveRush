use macroquad::prelude::*;
use specs::prelude::*;

use crate::components;

const BASIC_ENEMY_BASE_SPEED_X: f32 = 300.0;
const BASIC_ENEMY_BASE_SPEED_Y: f32 = 300.0;

pub struct BasicEnemy;

impl BasicEnemy {
    pub fn spawn(world: &mut World) -> Entity {
        world
            .create_entity()
            .with(components::Tag::BasicEnemy)
            .with(components::Position { x: 12.0, y: 123.0 })
            .with(components::Rectangle {
                width: 16.0,
                height: 16.0,
                color: BLUE,
            })
            .with(components::Velocity {
                x: BASIC_ENEMY_BASE_SPEED_X,
                y: BASIC_ENEMY_BASE_SPEED_Y,
            })
            .build()
    }
}
