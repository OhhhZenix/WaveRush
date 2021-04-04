use crate::{
    ecs::component::{
        position::Position,
        rectangle::Rectangle,
        tag::{Tag, TagType},
    },
    RENDER_SIZE,
};
use macroquad::prelude::RED;
use specs::{Builder, Entity, World, WorldExt};

pub fn spawn_player(world: &mut World) -> Entity {
    return world
        .create_entity()
        .with(Tag(TagType::Player))
        .with(Rectangle {
            w: 32.0,
            h: 32.0,
            color: RED,
        })
        .with(Position {
            x: RENDER_SIZE.x / 2.0,
            y: RENDER_SIZE.y / 2.0,
        })
        .build();
}
