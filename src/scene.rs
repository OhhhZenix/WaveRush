pub mod play_scene;

use crate::{RenderArgs, UpdateArgs};

pub trait Scene {
    fn update(&mut self, args: UpdateArgs);
    fn render(&mut self, args: RenderArgs);
}
