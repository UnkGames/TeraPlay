#include"FrameBuffer.h"
#include<iostream>

namespace TeraPlay {


	void FrameBuffers::SetupFrameBuffers()
	{
		const unsigned int width = 1920;
		const unsigned int height = 1080;


		// Create Frame Buffer Object
		glGenFramebuffers(1, &FBO);
		glBindFramebuffer(GL_FRAMEBUFFER, FBO);

		// Create Framebuffer Texture
		glGenTextures(1, &framebufferTexture);
		glBindTexture(GL_TEXTURE_2D, framebufferTexture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // Prevents edge bleeding
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Prevents edge bleeding

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, framebufferTexture, 0);

		// Create Render Buffer Object
		glGenRenderbuffers(1, &RBO);
		glBindRenderbuffer(GL_RENDERBUFFER, RBO);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, RBO);
	}

	FrameBuffers::~FrameBuffers()
	{
	}
	void FrameBuffers::Bind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, FBO);

	}
	void FrameBuffers::Unbind()
	{
		glBindTexture(GL_TEXTURE_2D, framebufferTexture);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
}