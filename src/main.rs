pub mod ecs;
pub mod state;

use amethyst::{
    core::TransformBundle,
    input::{InputBundle, StringBindings},
    prelude::*,
    renderer::{
        plugins::{RenderFlat2D, RenderToWindow},
        types::DefaultBackend,
        RenderingBundle,
    },
    utils::application_root_dir,
};
use ecs::system::player_movement_system::PlayerMovementSystem;
use state::play_state::PlayState;

pub const RENDER_WIDTH: f32 = 640.0;
pub const RENDER_HEIGHT: f32 = 360.0;

fn main() -> Result<(), amethyst::Error> {
    amethyst::start_logger(Default::default());

    let app_root = application_root_dir()?;
    let assets_dir = app_root.join("assets/");
    let display_config_path = app_root.join("config/display.ron");

    let binding_path = app_root.join("config/bindings.ron");
    let input_bundle =
        InputBundle::<StringBindings>::new().with_bindings_from_file(binding_path)?;

    let game_data = GameDataBuilder::default()
        .with_bundle(
            RenderingBundle::<DefaultBackend>::new()
                // The RenderToWindow plugin provides all the scaffolding for opening a window and drawing on it
                .with_plugin(
                    RenderToWindow::from_config_path(display_config_path)?
                        .with_clear([0.0, 0.0, 0.0, 1.0]),
                )
                // RenderFlat2D plugin is used to render entities with a `SpriteRender` component.
                .with_plugin(RenderFlat2D::default()),
        )?
        .with_bundle(TransformBundle::new())?
        .with_bundle(input_bundle)?
        .with(
            PlayerMovementSystem,
            "player_movement_system",
            &["input_system"],
        );

    let mut game = Application::new(assets_dir, PlayState, game_data)?;
    game.run();

    Ok(())
}
