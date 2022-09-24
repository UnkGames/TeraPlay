#include "OpenSaveProj_W.h"
using namespace ImGui;


OpenSaveProj_W::OpenSaveProj_W(bool OpenSaveProj, char* Directory)
{
	if (OpenSaveProj) {
		Begin("Open & Save Project");
		Button("Save", ImVec2{ ImGui::GetWindowSize().x, 0 });
		InputText("Directory", Directory,1000);
		Button("Cancel", ImVec2(ImGui::GetWindowSize().x / 2, 0));
		End();
	}
}
