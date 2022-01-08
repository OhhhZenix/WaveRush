use macroquad::prelude::{Color, Texture2D};

pub enum Renderable {
    Null,
    Rectangle {
        width: f32,
        height: f32,
        color: Color,
    },
    Sprite {
        texture: Texture2D,
        color: Color,
    },
}
