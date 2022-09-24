#pragma once
#include"3D/Renderer/Renderer.h"
class RuntimeToolBar
{
	int Textures_W = 0;
	int Textures_H = 0;
	GLuint PlayTexture = 0;
public:
	
	void SetupItems();
	void OnImGuiRender();
};

