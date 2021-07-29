use crate::BuildScript;

pub struct CopyAssets;

impl BuildScript for CopyAssets {
    fn run_script() {
        println!("cargo:rerun-if-changed=assets/*");

        let destination = std::env::var("OUT_DIR").unwrap();
        let destination = std::path::PathBuf::from(destination);
        let destination = destination
            .parent()
            .unwrap()
            .parent()
            .unwrap()
            .parent()
            .unwrap();
        println!("Assets Directory: {:?}", destination);

        let paths_to_copy = vec!["assets/"];
        let mut copy_options = fs_extra::dir::CopyOptions::new();
        copy_options.overwrite = true;

        fs_extra::copy_items(&paths_to_copy, destination, &copy_options).unwrap();
    }
}
