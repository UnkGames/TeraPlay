#pragma once

#include"3D/Renderer/Renderer.h"
#include<iostream>
#include<string>
#include<filesystem>


bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
namespace TeraPlay {
	class Textures {
	private:
	public:
		void TextureImporter(const char* FilePath, GLuint* out_texture, int* Width, int* Hieght);
		GLuint Texture;
		void bind(unsigned int Index);
		void unbind();
	};
}