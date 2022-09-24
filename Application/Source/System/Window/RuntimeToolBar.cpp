#include "RuntimeToolBar.h"
#include"3D/Renderer/Textures/TP_Textures.h"

#ifdef TP_PLATFORM_WINDOWS
	#define RUNTIME_RUN false
#endif // TP_PLATFORM_WINDOWS

void RuntimeToolBar::SetupItems()
{
	bool PB = LoadTextureFromFile("E:\\VisualProjects\\TeraPlay\\Engine\\Resources\\ToolBar\\TP_Play_Button.png", &PlayTexture, &Textures_W, &Textures_H);
}

void RuntimeToolBar::OnImGuiRender()
{
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
	ImGui::Begin("##Toolbar", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |ImGuiWindowFlags_None); 
	if (ImGui::ImageButton((void*)(intptr_t)PlayTexture, { 40, 40 })) {
		if (RUNTIME_RUN == true) {
			RUNTIME_RUN == false;
		}
		if (RUNTIME_RUN == false) {
			RUNTIME_RUN == true;
		}
	}
	ImGui::PopStyleColor(1);
	ImGui::End();
}
