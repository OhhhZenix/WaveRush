use crate::components;
use macroquad::prelude::*;
use specs::prelude::*;

pub struct SmartEnemy;

impl SmartEnemy {
    pub fn spawn(world: &mut World) -> Entity {
        world
            .create_entity()
            .with(components::Tag::SmartEnemy)
            .with(components::Position { x: 1.0, y: 1.0 })
            .with(components::Rectangle {
                width: 16.0,
                height: 16.0,
                color: YELLOW,
            })
            .build()
    }
}
