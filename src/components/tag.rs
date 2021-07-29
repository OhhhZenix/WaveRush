use specs::prelude::*;

#[derive(PartialEq)]
pub enum Tag {
    Player,
    BasicEnemy,
}

impl Component for Tag {
    type Storage = VecStorage<Self>;
}
