mod build_copy_assets;

use build_copy_assets::CopyAssets;

pub trait BuildScript {
    fn run_script();
}

fn main() {
    CopyAssets::run_script();
}
