#pragma once
#include"3D/Renderer/Renderer.h"
#include"3D/Renderer/FrameBuffer/FrameBuffer.h"

namespace TeraPlay {

	class Viewports
	{
	public:
		FrameBuffers v_FrameBuffers;

		void FBOSetup();
		void OnImGuiRender();
		//setup frame buffer object
		void SetViewport();
		//Bind frame buffer object
		void UnbindFBInViewport();
	};

}