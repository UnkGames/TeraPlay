#include "PropertiesPanel.h"
TeraPlay::MeshQuickSetup MeshQuickSetup_Ref;
void PropertiesPanel::OnImGuiRender()
{
	
	glm::mat4 Position = glm::mat4(1.0f);
	Position = glm::translate(Position, glm::vec3(10000000, 10, 10));
	glUniformMatrix4fv(glGetUniformLocation(ShaderCompiler.shaderProgram, "ModelLoc"), 1, GL_TRUE, glm::value_ptr(Position));

	ImGui::Begin("Properties");
	//ImGui::TextColored({0, 0, 1, 1}, "Transforms");
	ImGui::DragFloat3("Position", Pos, 0.1, -1000000000, 1000000000);
	//ImGui::Text("   ");
	//ImGui::DragFloat3("Rotation", Rot, 0.1, -1000000000, 1000000000);
	//ImGui::Text("   ");
	//ImGui::DragFloat3("Scale", Scl, 0.1, -1000000000, 1000000000);
	//ImGui::Text("---------------------------------------------------------------------------------------------------------------------");
	//ImGui::ColorEdit3("Object Color", &color.x);
	ImGui::End();
	//ShaderCompiler.SendUniform_Vec3("objectColor", color);
	//MeshQuickSetup_Ref.Cube = glm::translate(MeshQuickSetup_Ref.Cube, Positions_Vector);
	//MeshQuickSetup_Ref.Cube = glm::rotate(MeshQuickSetup_Ref.Cube, glm::radians(90.f), Rotations_Vector);
	//MeshQuickSetup_Ref.Cube = glm::scale(MeshQuickSetup_Ref.Cube, scales_Vector);
}
