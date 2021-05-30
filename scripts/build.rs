mod build_copy_assets;
mod build_gl_bindings;

use build_copy_assets::CopyAssets;
use build_gl_bindings::GLBindings;

pub trait BuildScript {
    fn run_script();
}

fn main() {
    CopyAssets::run_script();
    GLBindings::run_script();
}
