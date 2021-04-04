use macroquad::prelude::Color;
use specs::{prelude::*, Component};

#[derive(Component)]
pub struct Rectangle {
    pub w: f32,
    pub h: f32,
    pub color: Color,
}
