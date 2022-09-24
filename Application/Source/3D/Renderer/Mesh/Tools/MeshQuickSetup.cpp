#include "MeshQuickSetup.h"
namespace TeraPlay {
	VertexBuffers m_VertexBuffers;
	ShadersCompilers m_ShaderCompilers;
	Textures m_TextureLoader;
	VertexBuffers::Vertex vertices[] =
	{
		//Fronts
		glm::vec3(0.5f, 0.5f, 0.0f),		glm::vec3(0.0f, 0.0f,-1.0f),		glm::vec2(1.0f, 1.0f),
		glm::vec3(0.5f, -0.5f, 0.0f),		glm::vec3(0.0f, 0.0f,-1.0f),		glm::vec2(1.0f, 0.0f),
		glm::vec3(-0.5f, -0.5f, 0.0f),		glm::vec3(0.0f, 0.0f,-1.0f),		glm::vec2(0.0f, 0.0f),
		glm::vec3(-0.5f, 0.5f, 0.0f),		glm::vec3(0.0f, 0.0f,-1.0f),		glm::vec2(0.0f, 1.0f),

		glm::vec3(0.5f, 0.5f, 1.0f),		glm::vec3(0.0f, 0.0f, 1.0f),		glm::vec2(1.0f, 0.0f),
		glm::vec3(0.5f, -0.5f, 1.0f),		glm::vec3(0.0f, 0.0f, 1.0f),		glm::vec2(1.0f, 1.0f),
		glm::vec3(-0.5f, -0.5f, 1.0f),		glm::vec3(0.0f, 0.0f, 1.0f),		glm::vec2(0.0f, 1.0f),
		glm::vec3(-0.5f, 0.5f, 1.0f),		glm::vec3(0.0f, 0.0f, 1.0f),		glm::vec2(0.0f, 0.0f),


		//Lefts
		glm::vec3(0.5f, 0.5f, 1.0f),		glm::vec3(1.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 0.0f),
		glm::vec3(0.5f, -0.5f, 1.0f),		glm::vec3(1.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),
		glm::vec3(0.5f, -0.5f, 0.0f),		glm::vec3(1.0f, 0.0f, 0.0f),		glm::vec2(0.0f, 1.0f),
		glm::vec3(0.5f, 0.5f, 0.0f),		glm::vec3(1.0f, 0.0f, 0.0f),		glm::vec2(0.0f, 0.0f),

		glm::vec3(-0.5f, 0.5f, 1.0f),		glm::vec3(-1.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 0.0f),
		glm::vec3(-0.5f,-0.5f, 1.0f),		glm::vec3(-1.0f, 0.0f, 0.0f),		glm::vec2(1.0f, 1.0f),
		glm::vec3(-0.5f,-0.5f, 0.0f),		glm::vec3(-1.0f, 0.0f, 0.0f),		glm::vec2(0.0f, 1.0f),
		glm::vec3(-0.5f, 0.5f, 0.0f),		glm::vec3(-1.0f, 0.0f, 0.0f),		glm::vec2(0.0f, 0.0f),


		//Tops
		glm::vec3(0.5f, 0.5f, 1.0f),		glm::vec3(0.0f, 1.0f, 0.0f),		glm::vec2(1.0f, 0.0f),
		glm::vec3(0.5f, 0.5f, 0.0f),		glm::vec3(0.0f, 1.0f, 0.0f),		glm::vec2(1.0f, 1.0f),
		glm::vec3(-0.5f, 0.5f, 0.0f),		glm::vec3(0.0f, 1.0f, 0.0f),		glm::vec2(0.0f, 1.0f),
		glm::vec3(-0.5f, 0.5f, 1.0f),		glm::vec3(0.0f, 1.0f, 0.0f),		glm::vec2(0.0f, 0.0f),

		glm::vec3(0.5f, -0.5f, 1.0f),		glm::vec3(0.0f,-1.0f, 0.0f),		glm::vec2(1.0f, 0.0f),
		glm::vec3(0.5f, -0.5f, 0.0f),		glm::vec3(0.0f,-1.0f, 0.0f),		glm::vec2(1.0f, 1.0f),
		glm::vec3(-0.5f, -0.5f, 0.0f),		glm::vec3(0.0f,-1.0f, 0.0f),		glm::vec2(0.0f, 1.0f),
		glm::vec3(-0.5f, -0.5f, 1.0f),		glm::vec3(0.0f,-1.0f, 0.0f),		glm::vec2(0.0f, 0.0f)

	};
	Camera camera(1920, 1080, glm::vec3(0.0f, 0.0f, 2.0f));

	unsigned int Indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3, // second triangle

		4, 5, 7,
		5, 6, 7,

		//0, 4, 7,
		//0, 3, 7,
		//
		//2, 6, 5,
		//2, 1, 5,

		8, 9, 11,
		9, 10, 11,

		12, 13, 15,
		13, 14, 15,

		16, 17, 19,
		17, 18, 19,

		20, 21, 23,
		21, 22, 23
	};
	void MeshQuickSetup::SetupAMesh()
	{



		m_ShaderCompilers.SetShaders();
		m_ShaderCompilers.TP_VertexShaderSourceCompiler(*"Resources/Shaders/Base.vert");
		//here we will setup anything about meshes
		m_VertexBuffers.TP_VertexBufferSetup(vertices, 120, 3, Indices, 36);
		Textures m_TexturesImporter;
		int Texture_Width = 0;
		int Texture_Hieght = 0;
		GLuint Texture = 0;
		m_TexturesImporter.TextureImporter("Resources/Sci-Fi_Thing.jpg", &Texture, &Texture_Width, &Texture_Hieght);
		
	}
	void MeshQuickSetup::DrawAScene(GLFWwindow* window)
	{

		m_VertexBuffers.TP_RenderVertex(120, 3, Indices, 36, false);

		camera.Inputs(window);
		camera.Matrix(45.0f, 0.1f, 200.0f, m_ShaderCompilers, "camMatrix");
		m_ShaderCompilers.SendUniform_MatrixLoc("ModelLoc", Cube);
	}

	void MeshQuickSetup::ShaderSetup()
	{
		m_TextureLoader.bind(0);
		m_ShaderCompilers.CompileShaders();
		m_ShaderCompilers.SendUniformi("Base_Color_Tex", 0);
	}

	void MeshQuickSetup::ShaderEnd()
	{
		m_TextureLoader.unbind();
	}

}

