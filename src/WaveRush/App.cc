#include "App.h"

#include "WaveRush/Shader.h"

#include <array>

namespace wr
{

void App::init()
{
    sg_setup({
        .logger = {.func = slog_func},
        .environment = sglue_environment(),
    });

    // Vertex data: position (3 floats) + color (4 floats) per vertex
    constexpr std::array<float, 21> vertices{{
        0.0f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, // Top vertex
        0.5f,  -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, // Bottom-right vertex
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, // Bottom-left vertex
    }};

    trig_bind_.vertex_buffers[0] = sg_make_buffer({
        .data = SG_RANGE(vertices),
        .label = "vertex-buffer",
    });

    sg_shader shd = sg_make_shader(triangle_shader_desc(sg_query_backend()));

    sg_pipeline_desc pipeline_desc = {};
    pipeline_desc.shader = shd;
    pipeline_desc.layout.attrs[ATTR_triangle_position].format = SG_VERTEXFORMAT_FLOAT3;
    pipeline_desc.layout.attrs[ATTR_triangle_color0].format = SG_VERTEXFORMAT_FLOAT4;
    pipeline_desc.label = "triangle-pipeline";
    trig_pip_ = sg_make_pipeline(pipeline_desc);

    pass_action_.colors[0] = {
        .load_action = SG_LOADACTION_CLEAR,
        .clear_value = {0.0f, 0.0f, 0.0f, 1.0f},
    };
}

void App::frame()
{
    sg_begin_pass({
        .action = pass_action_,
        .swapchain = sglue_swapchain(),
    });
    sg_apply_pipeline(trig_pip_);
    sg_apply_bindings(trig_bind_);
    sg_draw(0, 3, 1);
    sg_end_pass();
    sg_commit();
}

void App::event(const sapp_event *e)
{
}

void App::cleanup()
{
    sg_shutdown();
}

} // namespace wr