use crate::entity::EntityType;
use bevy::prelude::*;

const PLAYER_SIZE: [f32; 2] = [32.0, 32.0];
const PLAYER_SPEED: f32 = 20.0;

pub struct PlayerPlugin;

impl Plugin for PlayerPlugin {
    fn build(&self, app: &mut bevy::prelude::AppBuilder) {
        app.add_startup_system(setup.system());
        app.add_startup_stage("game_setup", SystemStage::single(spawn_player.system()));
        app.add_system(player_movement.system());
    }
}

pub struct PlayerMaterials {
    default_skin: Handle<ColorMaterial>,
}

fn setup(mut commands: Commands, mut materials: ResMut<Assets<ColorMaterial>>) {
    commands.insert_resource(PlayerMaterials {
        default_skin: materials.add(Color::rgb(1.0, 1.0, 1.0).into()),
    });
}

fn spawn_player(mut commands: Commands, materials: Res<PlayerMaterials>) {
    let mut sprite = Sprite::new(Vec2::new(PLAYER_SIZE[0], PLAYER_SIZE[1]));
    sprite.resize_mode = SpriteResizeMode::Automatic;
    commands
        .spawn_bundle(SpriteBundle {
            material: materials.default_skin.clone(),
            sprite,
            ..Default::default()
        })
        .insert(EntityType::Player);
}

fn player_movement(
    keyboard_input: Res<Input<KeyCode>>,
    query: Query<(&mut Transform, &EntityType)>,
) {
    query.for_each_mut(|(mut transform, entity_type)| {
        if *entity_type != EntityType::Player {
            return;
        }

        if keyboard_input.pressed(KeyCode::W) {
            transform.translation.y += PLAYER_SPEED;
        }
        if keyboard_input.pressed(KeyCode::S) {
            transform.translation.y -= PLAYER_SPEED;
        }
        if keyboard_input.pressed(KeyCode::A) {
            transform.translation.x -= PLAYER_SPEED;
        }
        if keyboard_input.pressed(KeyCode::D) {
            transform.translation.x += PLAYER_SPEED;
        }
    });
}
