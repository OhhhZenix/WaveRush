use specs::prelude::*;

#[derive(PartialEq)]
pub enum Tag {
    Player,
    BasicEnemy,
    SmartEnemy,
}

impl Component for Tag {
    type Storage = VecStorage<Self>;
}
