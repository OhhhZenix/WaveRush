mod gl {
    include!(concat!(env!("OUT_DIR"), "/gl_bindings.rs"));
}

pub const APP_NAME: &str = "Wave Rush";
pub const GAME_SIZE: [u32; 2] = [640, 360];

fn main() {
    let (window, event_loop, gl) = {
        let event_loop = glutin::event_loop::EventLoop::new();

        let window_builder = glutin::window::WindowBuilder::new()
            .with_title(APP_NAME)
            .with_inner_size(glutin::dpi::LogicalSize::new(GAME_SIZE[0], GAME_SIZE[1]));

        let window = unsafe {
            glutin::ContextBuilder::new()
                .with_vsync(true)
                .build_windowed(window_builder, &event_loop)
                .unwrap()
                .make_current()
                .unwrap()
        };

        let gl =
            gl::Gl::load_with(|ptr| window.get_proc_address(ptr) as *const std::os::raw::c_void);

        (window, event_loop, gl)
    };

    let _vertices: [f32; 1] = [0.1];

    let _vertex_source = "";
    let _vertex_shader = unsafe { gl.CreateShader(gl::VERTEX_SHADER) };
    // unsafe { gl.ShaderSource(vertex_shader, 1, vertex_source, std::ptr::null()) };

    event_loop.run(move |event, _, control_flow| {
        *control_flow = glutin::event_loop::ControlFlow::Wait;
        match event {
            glutin::event::Event::LoopDestroyed => {
                return;
            }
            glutin::event::Event::MainEventsCleared => {
                unsafe {
                    gl.ClearColor(0.5, 1.0, 0.35, 1.0);
                    gl.Clear(gl::COLOR_BUFFER_BIT);
                }
                window.window().request_redraw();
            }
            glutin::event::Event::RedrawRequested(_) => {
                window.swap_buffers().unwrap();
            }
            glutin::event::Event::WindowEvent { ref event, .. } => match event {
                glutin::event::WindowEvent::Resized(physical_size) => {
                    window.resize(*physical_size);
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
