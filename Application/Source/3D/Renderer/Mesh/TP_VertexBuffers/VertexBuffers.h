#pragma once
#include"3D/Renderer/Renderer.h"
#include<GLFW/glfw3.h>
#include"glm/glm.hpp"
#include<vector>
namespace TeraPlay {

	class VertexBuffers
	{
	public:
		unsigned int VBO;
		unsigned int IBO;
		unsigned int VAO;
		GLuint Texture;

		struct Vertex
		{
			glm::vec3 Positions;
			glm::vec3 Normals;
			glm::vec2 UVs;
		};
		void TP_VertexBufferSetup(Vertex vertices[], unsigned int Vert, unsigned int Dimen, const unsigned int IPV[], unsigned int Ind/*UVs[]*/);
		void TP_RenderVertex(unsigned int Vert, unsigned int Dimen, unsigned int IPV[], unsigned int Ind, bool draw_arrays);

	};

}