#pragma once
#include"3D/Renderer/Renderer.h"
#include"3D/Renderer/Mesh/Tools/MeshQuickSetup.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include"3D/Renderer/Shaders/ShadersCompilers.h"
class PropertiesPanel
{
public:
	void OnImGuiRender();
	TeraPlay::ShadersCompilers ShaderCompiler;
	float color[3];
	float Pos[3] = { 0, 0, 0 };
	float Rot[3] = { 0, 0, 0 };
	float Scl[3] = { 1, 1, 1 };
	bool Transforms = true;
	glm::vec3 Positions_Vector = { Pos[1], Pos[2], Pos[3]};
	glm::vec3 Rotations_Vector = {Rot[1], Rot[2], Rot[3]};
	glm::vec3 scales_Vector = { Scl[1] ,Scl[2] ,Scl[3] };
};

