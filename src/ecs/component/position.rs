use core::f32;

use amethyst::ecs::{Component, DenseVecStorage};

pub struct Position {
    x: f32,
    y: f32,
}

impl Position {
    pub fn new(x: f32, y: f32) -> Self {
        return Self { x, y };
    }
}

impl Component for Position {
    type Storage = DenseVecStorage<Self>;
}
