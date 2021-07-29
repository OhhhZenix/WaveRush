use macroquad::prelude::draw_rectangle;
use specs::prelude::*;

use crate::{components, scale_factor};

pub struct RenderRectangle;

impl<'a> System<'a> for RenderRectangle {
    type SystemData = (
        ReadStorage<'a, components::Position>,
        ReadStorage<'a, components::Rectangle>,
    );

    fn run(&mut self, data: Self::SystemData) {
        let (pos, rect) = data;
        for (pos, rect) in (&pos, &rect).join() {
            draw_rectangle(
                pos.x,
                pos.y,
                rect.width * scale_factor(),
                rect.height * scale_factor(),
                rect.color,
            );
        }
    }
}
