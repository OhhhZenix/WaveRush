use macroquad::prelude::*;
use specs::prelude::*;

pub struct Rectangle {
    pub width: f32,
    pub height: f32,
    pub color: Color,
}

impl Component for Rectangle {
    type Storage = VecStorage<Self>;
}
