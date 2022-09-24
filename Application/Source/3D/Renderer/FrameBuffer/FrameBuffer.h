#pragma once

#include"3D/Renderer/Renderer.h"


namespace TeraPlay {
	class FrameBuffers
	{
	public:
		void SetupFrameBuffers();
		~FrameBuffers();
		unsigned int FBO;
		unsigned int RBO;
		unsigned int framebufferTexture;
		void Bind();
		void Unbind();
	};

}