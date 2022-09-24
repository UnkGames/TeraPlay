#pragma once
#include "imgui_impl_opengl3.h"
#include"3D/Renderer/Renderer.h"
#include"ContentBrowserPanel.h"
#include"PropertiesPanel.h"
#include"RuntimeToolBar.h"
#include"Core/Processor_Core.h"
namespace TeraPlay {

	class TP_API TP_Window
	{

	public:
		TP_Window();
		virtual ~TP_Window();
		void Run();

	};

}
