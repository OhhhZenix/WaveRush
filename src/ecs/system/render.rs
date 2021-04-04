use crate::{
    ecs::component::{position::Position, rectangle::Rectangle},
    RenderArgs,
};
use macroquad::prelude::draw_rectangle;
use specs::prelude::*;

pub struct RenderSystem;

impl<'a> System<'a> for RenderSystem {
    type SystemData = (
        Read<'a, RenderArgs>,
        ReadStorage<'a, Rectangle>,
        ReadStorage<'a, Position>,
    );

    fn run(&mut self, (render_args, rectangle, position): Self::SystemData) {
        for (rectangle, position) in (&rectangle, &position).join() {
            draw_rectangle(
                position.x,
                position.y,
                rectangle.w * render_args.scale.x,
                rectangle.h * render_args.scale.y,
                rectangle.color,
            );
        }
    }
}
