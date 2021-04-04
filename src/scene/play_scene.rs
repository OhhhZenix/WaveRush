use crate::{
    ecs::{
        component::{position::Position, rectangle::Rectangle, tag::Tag},
        entity::player::spawn_player,
        system::{player_movement::PlayerMovementSystem, render::RenderSystem},
    },
    scene::Scene,
    RenderArgs, UpdateArgs, Vec2, RENDER_SIZE,
};
use macroquad::prelude::*;
use specs::{Dispatcher, DispatcherBuilder, World, WorldExt};

pub struct PlayScene {
    pub world: World,
}

impl PlayScene {
    pub fn new() -> Self {
        let mut world = World::new();
        world.insert(UpdateArgs {
            dt: get_frame_time(),
        });
        world.insert(RenderArgs {
            scale: Vec2 {
                x: (screen_width() / RENDER_SIZE.x) as f32,
                y: (screen_height() / RENDER_SIZE.y) as f32,
            },
        });
        world.register::<Tag>();
        world.register::<Position>();
        world.register::<Rectangle>();
        spawn_player(&mut world);
        return Self { world };
    }
}

impl Scene for PlayScene {
    fn update(&mut self, args: UpdateArgs) {
        DispatcherBuilder::new()
            .with(PlayerMovementSystem, "player_movement_system", &[])
            .build()
            .dispatch(&mut self.world);

        self.world.maintain();

        let mut update_args = self.world.write_resource::<UpdateArgs>();
        *update_args = args;
    }

    fn render(&mut self, args: RenderArgs) {
        DispatcherBuilder::new()
            .with_thread_local(RenderSystem)
            .build()
            .dispatch(&mut self.world);

        self.world.maintain();

        let mut render_args = self.world.write_resource::<RenderArgs>();
        *render_args = args;
    }
}
