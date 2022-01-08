use crate::components;
use hecs::World;
use macroquad::prelude::{clamp, screen_height, screen_width};

pub struct ClampSystem;

impl ClampSystem {
    pub fn run(world: &mut World) {
        for (_, (position, renderable)) in
            world.query_mut::<(&mut components::Position, &components::Renderable)>()
        {
            let (entity_width, entity_height) = match renderable {
                components::Renderable::Null => (0.0, 0.0),
                components::Renderable::Rectangle {
                    width,
                    height,
                    color: _,
                } => (*width, *height),
                components::Renderable::Sprite { texture, color: _ } => {
                    (texture.width(), texture.height())
                }
            };

            position.value.x = clamp(
                position.value.x,
                entity_width / 2.0,
                screen_width() - (entity_width / 2.0),
            ) as f32;
            position.value.y = clamp(
                position.value.y,
                entity_height / 2.0,
                screen_height() - (entity_height / 2.0),
            ) as f32;
        }
    }
}
