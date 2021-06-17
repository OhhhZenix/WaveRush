mod build_copy_assets;
mod build_gl_bindings;
mod build_shaders;

use build_copy_assets::CopyAssets;
use build_gl_bindings::GLBindings;
use build_shaders::Shaders;

pub trait BuildScript {
    fn run_script();
}

fn main() {
    CopyAssets::run_script();
    GLBindings::run_script();
    Shaders::run_script();
}
