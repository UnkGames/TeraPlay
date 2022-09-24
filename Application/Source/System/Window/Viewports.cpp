#include "Viewports.h"
namespace TeraPlay {
}

void TeraPlay::Viewports::FBOSetup()
{
	v_FrameBuffers.SetupFrameBuffers();
}

void TeraPlay::Viewports::OnImGuiRender()
{

	ImGui::Begin("Scene");
	ImGui::Image((void*)(intptr_t)v_FrameBuffers.framebufferTexture, ImVec2(ImGui::GetWindowSize().x, ImGui::GetWindowSize().y - 35), { 0, 1 }, { 1, 0 });
	ImGui::End();
}

void TeraPlay::Viewports::SetViewport()
{
	v_FrameBuffers.Bind();

}

void TeraPlay::Viewports::UnbindFBInViewport()
{
	v_FrameBuffers.Unbind();

}
