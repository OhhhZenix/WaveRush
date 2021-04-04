use specs::{prelude::*, Component};

#[derive(PartialEq)]
pub enum TagType {
    Player,
    BasicEnemy,
    SmartEnemy,
}

#[derive(Component)]
pub struct Tag(pub TagType);
