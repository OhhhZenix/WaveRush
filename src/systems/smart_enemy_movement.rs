use specs::System;

pub struct SmartEnemyMovement;

impl<'a> System<'a> for SmartEnemyMovement {
    type SystemData = ();

    fn run(&mut self, data: Self::SystemData) {
        println!("hello!");
    }
}
