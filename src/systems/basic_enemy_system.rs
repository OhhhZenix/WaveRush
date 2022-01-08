use crate::components;
use hecs::World;
use macroquad::prelude::{screen_height, screen_width};

const BASIC_ENEMY_BASE_SPEED_X: f32 = 0.165;
const BASIC_ENEMY_BASE_SPEED_Y: f32 = 0.165;

pub struct BasicEnemySystem;

impl BasicEnemySystem {
    pub fn run(world: &mut World) {
        for (_, (tag, renderable, velocity, position)) in world.query_mut::<(
            &components::Tag,
            &components::Renderable,
            &mut components::Velocity,
            &mut components::Position,
        )>() {
            if *tag != components::Tag::BasicEnemy {
                continue;
            }

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

            position.value.x += BASIC_ENEMY_BASE_SPEED_X * velocity.x;
            position.value.y += BASIC_ENEMY_BASE_SPEED_Y * velocity.y;

            if position.value.x <= (entity_width / 2.0)
                || position.value.x >= screen_width() - (entity_width / 2.0)
            {
                velocity.x *= -1.0;
            }

            if position.value.y <= (entity_height / 2.0)
                || position.value.y >= screen_height() - (entity_height / 2.0)
            {
                velocity.y *= -1.0;
            }
        }
    }
}
