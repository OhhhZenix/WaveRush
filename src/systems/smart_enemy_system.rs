use crate::components;
use hecs::World;

const SMART_ENEMY_ATTRACTION: f32 = 0.035;
const SMART_ENEMY_REPULSION: f32 = -0.005;

pub struct SmartEnemySystem;

impl SmartEnemySystem {
    pub fn run(world: &mut World) {
        let mut entities = Vec::new();
        for (_, (tag, positon)) in world.query_mut::<(&components::Tag, &components::Position)>() {
            entities.push((tag.clone(), positon.clone()));
        }

        for (_, (_, smart_enemy_position)) in world
            .query_mut::<(&components::Tag, &mut components::Position)>()
            .into_iter()
            .filter(|(_, (tag, _))| **tag == components::Tag::SmartEnemy)
        {
            for (entity_tag, entity_position) in &entities {
                if *entity_tag == components::Tag::Player {
                    let distance = entity_position.value - smart_enemy_position.value;
                    smart_enemy_position.value += distance.normalize() * SMART_ENEMY_ATTRACTION;
                } else if *entity_tag == components::Tag::SmartEnemy {
                    let distance = entity_position.value - smart_enemy_position.value;
                    smart_enemy_position.value += distance.normalize() * SMART_ENEMY_REPULSION;
                }
            }
        }
    }
}
