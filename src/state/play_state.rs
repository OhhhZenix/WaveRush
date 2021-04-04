use crate::{
    ecs::{
        component::{position::Position, rectangle::Rectangle},
        entity::player::{spawn_player, Player},
    },
    RENDER_HEIGHT, RENDER_WIDTH,
};
use amethyst::{
    assets::{AssetStorage, Handle, Loader},
    core::Transform,
    prelude::{Builder, WorldExt},
    renderer::{Camera, ImageFormat, SpriteSheet, SpriteSheetFormat, Texture},
    shred::World,
    GameData, SimpleState, StateData,
};

pub struct PlayState;

fn initialise_camera(world: &mut World) {
    // Setup camera in a way that our screen covers whole arena and (0, 0) is in the bottom left.
    let mut transform = Transform::default();
    transform.set_translation_xyz(RENDER_WIDTH * 0.5, RENDER_HEIGHT * 0.5, 1.0);

    world
        .create_entity()
        .with(Camera::standard_2d(RENDER_WIDTH, RENDER_HEIGHT))
        .with(transform)
        .build();
}

fn load_assets(world: &mut World) -> Handle<SpriteSheet> {
    // Load the sprite sheet necessary to render the graphics.
    // The texture is the pixel data
    // `texture_handle` is a cloneable reference to the texture
    let texture_handle = {
        let loader = world.read_resource::<Loader>();
        let texture_storage = world.read_resource::<AssetStorage<Texture>>();
        loader.load(
            "texture/characters.png",
            ImageFormat::default(),
            (),
            &texture_storage,
        )
    };

    let loader = world.read_resource::<Loader>();
    let sprite_sheet_store = world.read_resource::<AssetStorage<SpriteSheet>>();

    return loader.load(
        "texture/characters.ron", // Here we load the associated ron file
        SpriteSheetFormat(texture_handle),
        (),
        &sprite_sheet_store,
    );
}

impl SimpleState for PlayState {
    fn on_start(&mut self, data: StateData<'_, GameData<'_, '_>>) {
        let world = data.world;

        world.register::<Position>();
        world.register::<Rectangle>();
        world.register::<Player>();

        initialise_camera(world);

        let sprite_sheet_handle = load_assets(world);
        spawn_player(world, sprite_sheet_handle);
    }
}
