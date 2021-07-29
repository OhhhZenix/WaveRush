use crate::components;
use macroquad::prelude::*;
use specs::prelude::*;

pub struct Player;

impl Player {
    pub fn spawn(world: &mut World) -> Entity {
        world
            .create_entity()
            .with(components::Tag::Player)
            .with(components::Position {
                x: screen_width() / 2.0,
                y: screen_height() / 2.0,
            })
            .with(components::Rectangle {
                width: 32.0,
                height: 32.0,
                color: RED,
            })
            .build()
    }
}
