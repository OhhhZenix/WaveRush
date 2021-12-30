use crate::{components, scale_factor};
use macroquad::prelude::*;
use specs::prelude::*;

pub struct RenderRectangle;

impl<'a> System<'a> for RenderRectangle {
    type SystemData = (
        ReadStorage<'a, components::Position>,
        ReadStorage<'a, components::Rectangle>,
    );

    fn run(&mut self, data: Self::SystemData) {
        #[cfg(feature = "profile")]
        puffin::profile_scope!(stdext::function_name!());

        let (pos, rect) = data;
        (&pos, &rect).join().for_each(|(pos, rect)| {
            draw_rectangle(
                pos.x * scale_factor(),
                pos.y * scale_factor(),
                rect.width * scale_factor(),
                rect.height * scale_factor(),
                rect.color,
            );
        });
    }
}
