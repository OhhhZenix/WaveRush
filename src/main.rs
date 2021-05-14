pub mod entity;
pub mod player;
pub mod state;

use bevy::prelude::*;
use entity::EntityType;
use player::PlayerPlugin;

pub const ARENA_WIDTH: f32 = 640.0;
pub const ARENA_HEIGHT: f32 = 360.0;

fn main() {
    App::build()
        .add_plugins(DefaultPlugins)
        .add_plugin(PlayerPlugin)
        .add_startup_system(setup.system())
        .add_system_to_stage(CoreStage::PreUpdate, size_scaling.system())
        .run();
}

fn setup(mut commands: Commands) {
    commands.spawn_bundle(OrthographicCameraBundle::new_2d());
}

fn size_scaling(windows: Res<Windows>, query: Query<&mut Transform, With<EntityType>>) {
    query.for_each_mut(|mut transform| {
        let window = windows.get_primary().unwrap();
        let scale_x = window.width() / ARENA_WIDTH;
        let scale_y = window.height() / ARENA_HEIGHT;
        transform.scale = Vec3::new(scale_x, scale_y, 1.0);
    });
}
