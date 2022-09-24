#include "ShadersCompilers.h"

#include<vector>
using namespace std;
namespace TeraPlay {
	void ShadersCompilers::SetShaders()
	{
		const char* VertexShader = {
			R"(
 
			#version 330 core
			layout (location = 0) in vec3 aPos;
			layout (location = 1) in vec3 aNormal;
			layout (location = 2) in vec2 TUVs;
			uniform mat4 camMatrix;
			uniform mat4 ModelLoc;
			out vec3 FragPos;
			out vec3 Normal;
			out vec2 TUVs_Out;
			void main()
			{
				gl_Position = camMatrix * ModelLoc * vec4(aPos.x, aPos.y, aPos.z, 1.0);
				FragPos = vec3(ModelLoc * vec4(aPos, 1.0));
				TUVs_Out = TUVs;
				Normal = aNormal;
			}
			
			)"
		};
		const char* FragmentShader = {
			R"(
			#version 330 core

			uniform sampler2D diffuse;
			uniform sampler2D specular;
			float shininess;
			
			out vec4 FragColor;
			in vec3 FragPos;
			in vec3 Normal;
			in vec2 TUVs_Out;
			uniform sampler2D Base_Color_Tex;
			/*uniform*/ vec3 lightPos = vec3(2,-1,-1);
			uniform vec3 objectColor = vec3(1.0f, 1.0f, 1.0f);
			vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
			void main()
			{
				//FragColor = texture(Base_Color_Tex, TUVs_Out);
				vec3 norm = normalize(Normal);
				vec3 lightDir = normalize(lightPos - FragPos);
				float diff = max(dot(norm, lightDir), 0.0);
				vec3 diffuse = diff * lightColor;
				float ambientStrength = 0.1;
				vec3 ambient = ambientStrength * lightColor;
				vec3 result = (ambient + diffuse) * objectColor;
				FragColor = vec4(result, 1.0) * texture(Base_Color_Tex, TUVs_Out);

			}
			)"
		};


		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &VertexShader, NULL);
		glCompileShader(vertexShader);
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &FragmentShader, NULL);
		glCompileShader(fragmentShader);
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
	}

	void ShadersCompilers::CompileShaders()
	{
		glUseProgram(shaderProgram);
	}
	
	void ShadersCompilers::TP_VertexShaderSourceCompiler(const char FileName)
	{
		std::fstream stream(&FileName);
		stream.open("Resources/Shaders/Base.vert");
		vector<string> Line;
		string Source;
		while (stream>>Source)
		{
			if (getline(stream, Source)) {
				Line.push_back(Source);
			}
			
			
		}
		
		 //Source + (Source + R"(\n)" + "\n"));


	}

	void ShadersCompilers::TP_FragmentShaderSourceCompiler(const char FileName)
	{

	}

	void ShadersCompilers::SendUniformi(const std::string& name, int Value)
	{
		glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), Value);

	}

	void ShadersCompilers::SendUniform_MatrixLoc(const char* uniform, glm::mat4 TransposValue)
	{
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, uniform), 1 , GL_FALSE, glm::value_ptr(TransposValue));

	}

	void ShadersCompilers::SendUniform_Vec3(const char* uniform, glm::vec3 TransposValue)
	{
		glUniform3fv(glGetUniformLocation(shaderProgram, uniform), 1, &TransposValue[0]);
	}
}