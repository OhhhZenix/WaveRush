use crate::components;
use hecs::World;
use macroquad::prelude::{draw_rectangle, draw_texture};

pub struct RenderSystem;

impl RenderSystem {
    pub fn run(world: &mut World) {
        for (_, (renderable, position)) in
            &mut world.query::<(&components::Renderable, &components::Position)>()
        {
            match renderable {
                components::Renderable::Null => continue,
                components::Renderable::Rectangle {
                    width,
                    height,
                    color,
                } => draw_rectangle(
                    position.value.x - (width / 2.0),
                    position.value.y - (height / 2.0),
                    *width,
                    *height,
                    *color,
                ),
                components::Renderable::Sprite { texture, color } => draw_texture(
                    *texture,
                    position.value.x - (texture.width() / 2.0),
                    position.value.y - (texture.height() / 2.0),
                    *color,
                ),
            }
        }
    }
}
