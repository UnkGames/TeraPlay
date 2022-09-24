#pragma once
#include"3D/Renderer/Renderer.h"
#include<GLFW/glfw3.h>
#include"3D/Renderer/Mesh/TP_VertexBuffers/VertexBuffers.h"
#include"3D/Renderer/Textures/TP_Textures.h"
#include"3D/Renderer/Shaders/ShadersCompilers.h"
#include"3D/Renderer/Camera/Camera.h"


namespace TeraPlay {
	class MeshQuickSetup
	{
	public:
		void SetupAMesh();
		void DrawAScene(GLFWwindow* window);
		void ShaderSetup();
		void ShaderEnd();

		glm::mat4 Cube = glm::mat4(1.0f);

	};

}