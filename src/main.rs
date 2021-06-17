pub mod graphics;

pub const APP_NAME: &str = "Wave Rush";
pub const GAME_SIZE: [u32; 2] = [640, 360];

pub fn test() {}

fn main() {
    env_logger::init();

    let event_loop = winit::event_loop::EventLoop::new();

    let window = winit::window::WindowBuilder::new()
        .with_title(APP_NAME)
        .with_min_inner_size(winit::dpi::PhysicalSize {
            width: GAME_SIZE[0],
            height: GAME_SIZE[1],
        })
        .with_inner_size(winit::dpi::PhysicalSize {
            width: 1280,
            height: 720,
        })
        .build(&event_loop)
        .expect("Could not create a window!");

    let mut renderer = futures::executor::block_on(graphics::Renderer::new(&window));

    // let mut world = World::new();

    event_loop.run(move |event, _, control_flow| {
        *control_flow = winit::event_loop::ControlFlow::Poll;
        match event {
            winit::event::Event::LoopDestroyed => {
                return;
            }
            winit::event::Event::MainEventsCleared => {
                match renderer.render() {
                    Ok(_) => {}
                    // Recreate the swap_chain if lost
                    Err(wgpu::SwapChainError::Lost) => renderer.resize(renderer.size()),
                    // The system is out of memory, we should probably quit
                    Err(wgpu::SwapChainError::OutOfMemory) => {
                        *control_flow = winit::event_loop::ControlFlow::Exit
                    }
                    // All other errors (Outdated, Timeout) should be resolved by the next frame
                    Err(error) => eprintln!("{:?}", error),
                }
            }
            winit::event::Event::RedrawRequested(_) => {
                // renderer.swap_buffers();
            }
            winit::event::Event::WindowEvent {
                ref event,
                window_id,
            } if window_id == window.id() => match event {
                winit::event::WindowEvent::Resized(physical_size) => {
                    renderer.resize(*physical_size);
                }
                winit::event::WindowEvent::ScaleFactorChanged { new_inner_size, .. } => {
                    renderer.resize(**new_inner_size);
                }
                winit::event::WindowEvent::CloseRequested => {
                    *control_flow = winit::event_loop::ControlFlow::Exit
                }
                _ => (),
            },
            _ => (),
        }
    });
}
