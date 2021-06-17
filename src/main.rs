pub(crate) mod gl {
    include!(concat!(env!("OUT_DIR"), "/gl_bindings.rs"));
}

pub mod graphics;

pub const APP_NAME: &str = "Wave Rush";
pub const GAME_SIZE: [u32; 2] = [640, 360];

pub fn test() {}

fn main() {
    env_logger::init();

    let event_loop = glutin::event_loop::EventLoop::new();

    let mut renderer = graphics::Renderer::new(&event_loop);

    // let mut world = World::new();

    event_loop.run(move |event, _, control_flow| {
        *control_flow = glutin::event_loop::ControlFlow::Wait;
        match event {
            glutin::event::Event::LoopDestroyed => {
                return;
            }
            glutin::event::Event::MainEventsCleared => {
                renderer.begin();
                renderer.render();
                renderer.end();
            }
            glutin::event::Event::RedrawRequested(_) => {
                renderer.swap_buffers();
            }
            glutin::event::Event::WindowEvent { ref event, .. } => match event {
                glutin::event::WindowEvent::Resized(physical_size) => {
                    renderer.resize(*physical_size);
                }
                glutin::event::WindowEvent::CloseRequested => {
                    *control_flow = glutin::event_loop::ControlFlow::Exit
                }
                _ => (),
            },
            _ => (),
        }
    });
}
