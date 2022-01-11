use crate::components;
use hecs::{Entity, World};
use macroquad::prelude::{load_texture, screen_height, screen_width, Vec2, WHITE};
use pollster::block_on;
use rand::{thread_rng, Rng};

const BASIC_ENEMY_WIDTH: f32 = 24.0;
const BASIC_ENEMY_HEIGHT: f32 = 24.0;

pub struct BasicEnemy;

impl BasicEnemy {
    pub fn spawn(world: &mut World) -> Entity {
        let mut rng = thread_rng();

        let (position_x, position_y) = (
            rng.gen_range(0..((screen_width() - BASIC_ENEMY_WIDTH) as u32)),
            rng.gen_range(0..((screen_height() - BASIC_ENEMY_HEIGHT) as u32)),
        );

        let velocity_x = {
            if rng.gen_range(1..100) < 50 {
                1.0
            } else {
                -1.0
            }
        };

        let velocity_y = {
            if rng.gen_range(1..100) > 50 {
                1.0
            } else {
                -1.0
            }
        };

        world.spawn((
            components::Tag::BasicEnemy,
            components::Position {
                value: Vec2::new(position_x as f32, position_y as f32),
            },
            // components::Renderable::Rectangle {
            //     width: BASIC_ENEMY_WIDTH,
            //     height: BASIC_ENEMY_HEIGHT,
            //     color: Color::from_rgba(155, 0, 0, 255),
            // },
            components::Renderable::Sprite {
                texture: block_on(load_texture("assets/textures/basic_enemy.png")).unwrap(),
                color: WHITE,
            },
            components::Velocity {
                value: Vec2::new(velocity_x, velocity_y),
            },
        ))
    }
}
