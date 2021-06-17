use glutin::window::Window;

use crate::{gl, APP_NAME, GAME_SIZE};

pub struct Renderer {
    context: glutin::ContextWrapper<glutin::PossiblyCurrent, Window>,
    gl: gl::Gl,
}

impl Renderer {
    pub fn new(event_loop: &glutin::event_loop::EventLoop<()>) -> Self {
        let context = {
            let window_builder = glutin::window::WindowBuilder::new()
                .with_visible(false)
                .with_title(APP_NAME)
                .with_min_inner_size(glutin::dpi::LogicalSize::new(GAME_SIZE[0], GAME_SIZE[1]))
                .with_inner_size(glutin::dpi::PhysicalSize::new(1280.0, 720.0));

            let context = unsafe {
                glutin::ContextBuilder::new()
                    .build_windowed(window_builder.clone(), &event_loop)
                    .unwrap()
                    .make_current()
                    .unwrap()
            };

            context
        };
        context.window().set_visible(true);

        let gl = gl::Gl::load_with(|symbol| context.get_proc_address(symbol));

        Renderer { context, gl }
    }

    pub fn begin(&self) {
        unsafe {
            self.gl.Clear(gl::COLOR_BUFFER_BIT);
            self.gl.ClearColor(0.5, 1.0, 0.35, 1.0);
        }
        println!("Begin");
    }

    pub fn end(&self) {
        self.context.window().request_redraw();
    }

    pub fn render(&self) {}

    pub fn resize(&mut self, new_size: glutin::dpi::PhysicalSize<u32>) {
        self.context.resize(new_size);
    }

    pub fn size(&self) -> glutin::dpi::PhysicalSize<u32> {
        return self.context.window().inner_size();
    }

    pub fn swap_buffers(&self) {
        self.context.swap_buffers().unwrap();
    }
}
