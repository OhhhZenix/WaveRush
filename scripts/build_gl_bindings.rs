use crate::BuildScript;

pub struct GLBindings;

impl BuildScript for GLBindings {
    fn run_script() {
        println!("cargo:rerun-if-changed=build_gl_bindings.rs");

        let destination = std::env::var("OUT_DIR").unwrap();
        let mut file =
            std::fs::File::create(std::path::Path::new(&destination).join("gl_bindings.rs"))
                .unwrap();
        let registry = gl_generator::Registry::new(
            gl_generator::Api::Gl,
            (4, 5),
            gl_generator::Profile::Core,
            gl_generator::Fallbacks::All,
            [],
        );

        if std::env::var("CARGO_FEATURE_DEBUG").is_ok() {
            registry
                .write_bindings(gl_generator::DebugStructGenerator, &mut file)
                .unwrap();
        } else {
            registry
                .write_bindings(gl_generator::StructGenerator, &mut file)
                .unwrap();
        }
    }
}
