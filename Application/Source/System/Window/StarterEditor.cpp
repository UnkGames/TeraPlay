#include "StarterEditor.h"
#include"ContentBrowserPanel.h"
#include"System/Window/OpenSaveProj_W.h"
#include"API/Source/TPGF_Importer.h"
#include"GameCompiler.h"
#include"Viewports.h"
#include"3D/Renderer/Mesh/Tools/MeshQuickSetup.h"

using namespace ImGui;
namespace TeraPlay {
	ContentBrowserPanel m_ContentBrowser; 
	ProjectLoader m_ProjectLoader;
	PropertiesPanel m_PropertiesPanel;
	MeshQuickSetup s_MeshQuickSetup;
	Viewports m_viewport;
	RuntimeToolBar runtime_toolbar;
	TP_Window::TP_Window()
	{


	}

	TP_Window::~TP_Window()
	{
	}

	void TP_Window::Run() {

		GLFWwindow* window;
		glfwInit();
		window = glfwCreateWindow(1920, 1080, "TeraPlay Editor", NULL, NULL);
		glfwMakeContextCurrent(window);
		glfwSwapInterval(1); // Enable vsync
		glewInit();
		static bool opt_fullscreen = true;
		static bool opt_padding = false;
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;


		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;   // Enable Gamepad Controls
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init();

		// Setup style
		ImGui::StyleColorsTeraPlay();
		//ImGui::StyleColorsClassic();
		bool DirectoryBrowser = false;
		ImVec4 clear_color = ImVec4(0.9f, 0.9f, 1.0f, 1.00f);

		clear_color = ImVec4(0.0f, 0.0f, 0.1f, 1.00f);
		clear_color = ImVec4(1.0f, 0.9f, 0.8f, 1.00f);

		s_MeshQuickSetup.SetupAMesh();
		bool OpenSaveProj = false;

		m_ContentBrowser.Setup();
		runtime_toolbar.SetupItems();

		m_viewport.FBOSetup();

		
		while (!glfwWindowShouldClose(window))
		{

			
			glfwPollEvents();			
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			glEnable(GL_DEPTH_TEST);
			ImGui::DockSpaceOverViewport();

			
			BeginMainMenuBar();
			if (BeginMenu("File")) 
			{ 
				if (MenuItem("Save Project")) { OpenSaveProj = true; }
				if (MenuItem("Open Project")) { OpenSaveProj = true; }
				EndMenu();

			}
			ImGui::EndMainMenuBar();

			if (OpenSaveProj) {
				char ProjPath;

				m_ProjectLoader.ProjPath = strcpy_s(&ProjPath, m_ProjectLoader.ProjPath.size() + 100, m_ProjectLoader.ProjPath.c_str());
				OpenSaveProj_W::OpenSaveProj_W(OpenSaveProj, &ProjPath);
			}


			m_ContentBrowser.OnImGuiRender();
			runtime_toolbar.OnImGuiRender();
			m_PropertiesPanel.OnImGuiRender();
			m_viewport.OnImGuiRender();
			ImGui::Render();
			m_viewport.SetViewport();
			int display_w, display_h;
			glfwGetFramebufferSize(window, &display_w, &display_h);
			glViewport(0, 0, display_w, display_h);
			glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
			glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
			s_MeshQuickSetup.DrawAScene(window);
			s_MeshQuickSetup.ShaderSetup();
			s_MeshQuickSetup.ShaderEnd();
			m_viewport.UnbindFBInViewport();


			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
			{
				GLFWwindow* backup_current_context = glfwGetCurrentContext();
				UpdatePlatformWindows();
				RenderPlatformWindowsDefault();
				glfwMakeContextCurrent(backup_current_context);
			}


			glfwSwapBuffers(window);

		}

		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		glfwDestroyWindow(window);
		glfwTerminate();
	}
}