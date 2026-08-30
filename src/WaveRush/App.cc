#include "App.h"

#include "WaveRush/Shader.h"

#include <array>
#include <cstdint>
#include <glm/glm.hpp>

namespace wr
{

struct QuadVertex
{
    glm::vec3 position;
    glm::vec4 color;
};

void App::init()
{
    sg_setup({
        .logger = {.func = slog_func},
        .environment = sglue_environment(),
    });

    constexpr std::array<QuadVertex, 4> vertices = {{
        {{-0.5f, 0.5f, 0.5f}, {1.0f, 0.0f, 0.0f, 1.0f}},
        {{0.5f, 0.5f, 0.5f}, {0.0f, 1.0f, 0.0f, 1.0f}},
        {{0.5f, -0.5f, 0.5f}, {0.0f, 0.0f, 1.0f, 1.0f}},
        {{-0.5f, -0.5f, 0.5f}, {1.0f, 1.0f, 0.0f, 1.0f}},
    }};
    quad_bind_.vertex_buffers[0] = sg_make_buffer({
        .usage = {.vertex_buffer = true},
        .data = SG_RANGE(vertices),
        .label = "vertex-buffer",
    });

    constexpr std::array<std::uint16_t, 6> indices = {0, 1, 2, 0, 2, 3};
    quad_bind_.index_buffer = sg_make_buffer({
        .usage = {.index_buffer = true},
        .data = SG_RANGE(indices),
        .label = "quad-indices",
    });

    sg_shader shd = sg_make_shader(quad_shader_desc(sg_query_backend()));

    sg_pipeline_desc pipeline_desc = {};
    pipeline_desc.shader = shd;
    pipeline_desc.index_type = SG_INDEXTYPE_UINT16;
    pipeline_desc.layout.attrs[ATTR_quad_position].format = SG_VERTEXFORMAT_FLOAT3;
    pipeline_desc.layout.attrs[ATTR_quad_color].format = SG_VERTEXFORMAT_FLOAT4;
    pipeline_desc.label = "quad-pipeline";
    quad_pip_ = sg_make_pipeline(pipeline_desc);

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
    sg_apply_pipeline(quad_pip_);
    sg_apply_bindings(quad_bind_);
    sg_draw(0, 6, 1);
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