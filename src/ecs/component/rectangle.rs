use amethyst::ecs::{Component, DenseVecStorage};

pub struct Rectangle {
    w: f32,
    h: f32,
    color: [f32; 4],
}

impl Rectangle {
    pub fn new(w: f32, h: f32, color: [f32; 4]) -> Self {
        return Self { w, h, color };
    }
}

impl Component for Rectangle {
    type Storage = DenseVecStorage<Self>;
}
