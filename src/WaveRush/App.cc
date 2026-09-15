#include "App.h"

#include "WaveRush/Contants.h"
#include "WaveRush/Shader.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/fwd.hpp"

#include <array>
#include <glm/glm.hpp>

namespace wr
{

void App::init()
{
    sg_setup({
        .logger = {.func = slog_func},
        .environment = sglue_environment(),
    });

    quad_bind_.vertex_buffers[0] = sg_make_buffer({
        .size = sizeof(QuadVertex) * wr::MAX_QUAD_VERTICES,
        .usage = {.vertex_buffer = true, .dynamic_update = true},
        .label = "quad-vertices",
    });

    quad_bind_.index_buffer = sg_make_buffer({
        .size = sizeof(std::uint32_t) * wr::MAX_QUAD_INDICES,
        .usage = {.index_buffer = true, .dynamic_update = true},
        .label = "quad-indices",
    });

    sg_shader shd = sg_make_shader(quad_shader_desc(sg_query_backend()));
    sg_pipeline_desc pipeline_desc = {};
    pipeline_desc.shader = shd;
    pipeline_desc.index_type = SG_INDEXTYPE_UINT32;
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
    // stuff
    draw_quad({-0.5f, -0.5f}, {1.0f, 1.0f}, {1.0f, 0.0f, 0.0f, 1.0f});

    flush_quads();
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

void App::flush_quads()
{
    if (quad_vertices_.empty() || quad_indices_.empty())
    {
        return;
    }

    sg_update_buffer(quad_bind_.vertex_buffers[0], SG_RANGE(quad_vertices_));
    sg_update_buffer(quad_bind_.index_buffer, SG_RANGE(quad_indices_));

    sg_apply_pipeline(quad_pip_);
    sg_apply_bindings(quad_bind_);
    sg_draw(0, static_cast<int>(quad_indices_.size()), 1);

    quad_vertices_.clear();
    quad_indices_.clear();
}

void App::draw_quad(const glm::vec2 &pos, const glm::vec2 &size, const glm::vec4 &color)
{
    constexpr std::uint32_t vertex_count = 4;
    constexpr std::uint32_t index_count = 6;

    if (quad_vertices_.size() + vertex_count > wr::MAX_QUAD_VERTICES ||
        quad_indices_.size() + index_count > wr::MAX_QUAD_INDICES)
    {
        flush_quads();
    }

    const std::uint32_t vertex_offset = static_cast<std::uint32_t>(quad_vertices_.size());

    quad_vertices_.push_back({
        .position = {pos.x, pos.y, 0.0f},
        .color = color,
    });

    quad_vertices_.push_back({
        .position = {pos.x + size.x, pos.y, 0.0f},
        .color = color,
    });

    quad_vertices_.push_back({
        .position = {pos.x + size.x, pos.y + size.y, 0.0f},
        .color = color,
    });

    quad_vertices_.push_back({
        .position = {pos.x, pos.y + size.y, 0.0f},
        .color = color,
    });

    quad_indices_.push_back(vertex_offset + 0);
    quad_indices_.push_back(vertex_offset + 1);
    quad_indices_.push_back(vertex_offset + 2);

    quad_indices_.push_back(vertex_offset + 2);
    quad_indices_.push_back(vertex_offset + 3);
    quad_indices_.push_back(vertex_offset + 0);
}

} // namespace wr