#include "runtime/function/render/include/surface.h"


using namespace VE;

// VSurfaceRHI: now vulkan rhi only
int SurfaceRHI::initialize(SurfaceIO* io, const FrameBuffer* framebuffer)
{
    Scene tmp_scene;
    m_vulkan_manager = new VVulkanManager(io->m_window, tmp_scene, m_virtual_renderer);
    // m_vulkan_manager = new VVulkanManager(io->m_window, *framebuffer->m_scene, m_virtual_renderer);
    m_window = io->m_window;
    return 0;
}