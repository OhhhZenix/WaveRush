use amethyst::{
    assets::Handle,
    core::Transform,
    ecs::{Component, DenseVecStorage},
    prelude::{Builder, WorldExt},
    renderer::{SpriteRender, SpriteSheet},
    shred::World,
};

use crate::ecs::component::{position::Position, rectangle::Rectangle};

pub struct Player {
    pub speed_level: u32,
}

impl Player {
    pub fn new() -> Self {
        return Self { speed_level: 1 };
    }
}

impl Component for Player {
    type Storage = DenseVecStorage<Self>;
}

pub fn spawn_player(world: &mut World, sprite_sheet_handle: Handle<SpriteSheet>) {
    let sprite_render = SpriteRender::new(sprite_sheet_handle, 0);
    let mut transform = Transform::default();
    transform.set_translation_xyz(100.0, 100.0, 0.0);

    world
        .create_entity()
        .with(Player::new())
        .with(transform)
        .with(sprite_render)
        .build();
}
