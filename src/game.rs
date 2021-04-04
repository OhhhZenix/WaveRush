use crate::scene::Scene;

pub struct Game<S: Scene> {
    scene: S,
}

impl<S: Scene> Game<S> {
    pub fn new(scene: S) -> Self {
        return Self { scene };
    }

    pub fn get_scene(&mut self) -> &mut S {
        return &mut self.scene;
    }
}
