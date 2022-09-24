#pragma once
#include "imgui_impl_opengl3.h"
#include"3D/Renderer/Renderer.h"
#include"Core/Processor_Core.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include<fstream>
#include<sstream>
#include<iostream>
#include<string>
namespace TeraPlay {
	class ShadersCompilers
	{
	public:
		
		void SetShaders();
		void CompileShaders();
		void TP_VertexShaderSourceCompiler(const char FileName);
		void TP_FragmentShaderSourceCompiler(const char FileName);
		void SendUniformi(const std::string& name, int Value);
		void SendUniform_MatrixLoc(const char* uniform, glm::mat4 TransposValue);
		void SendUniform_Vec3(const char* uniform, glm::vec3 TransposValue);


		GLuint vertexShader;
		GLuint fragmentShader;
		GLuint shaderProgram;
		std::string VertexShaderSource;

	};

}