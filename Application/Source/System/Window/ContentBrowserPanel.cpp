#include"3D/Renderer/Renderer.h"
#include <d3d10_1.h>
#include <d3d10.h>
#include <tchar.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include<memory>
#include"3D/Renderer/Textures/TP_Textures.h"
#include"assimp/Importer.hpp"
#include"ContentBrowserPanel.h"
#include<filesystem>
#include"3D/Renderer/Shaders/ShadersCompilers.h"

namespace TeraPlay {
    static const std::filesystem::path s_AssetPath = "Assets";
    int i = 0;
    GLuint Content_Items_texture[] = {0};
    GLuint Content_textures;
    char* ImagePath;
    Textures textures_importer;
    ShadersCompilers shader_compilers;
    ContentBrowserPanel::ContentBrowserPanel()
        :m_CurrentDirectory(s_AssetPath) {
        std::filesystem::create_directory(s_AssetPath);
    }
    void ContentBrowserPanel::OnImGuiRender() {
        ImGui::Begin("Content Browser");

        if (m_CurrentDirectory != std::filesystem::path(s_AssetPath))
        {
            if (ImGui::Button("<-"))
            {
                m_CurrentDirectory = m_CurrentDirectory.parent_path();
            }
        }

        int ColumnsCount = (int)(ImGui::GetContentRegionAvail().x / 144);
        if (ColumnsCount < 1) {
            ColumnsCount = 1;
        }
        ImGui::Columns( ColumnsCount, 0, false);
        for (auto& it : std::filesystem::directory_iterator(m_CurrentDirectory)) {
            std::string path = it.path().filename().string();
            auto relativepath = std::filesystem::relative(it.path(), s_AssetPath);
            if (it.path().extension() == ".jpg") {
                i = 0;
            }
            if (it.path().extension() == ".png") {
                i = 0;
            }
            if (it.path().extension() == ".obj") {
                i = 2;
            }
            if (it.is_directory()) {
                i = 1;
            }
            ImGui::ImageButton((void*)Content_Items_texture[i], { 100,100 });

            if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
            {
                if (it.path().extension() == ".obj") {
                    //OBJLoader.Load(it.path().string());
                }

                if (it.is_directory())
                    m_CurrentDirectory /= relativepath.filename();
                
            }
            ImGui::TextWrapped(path.c_str());

            ImGui::NextColumn();
            
            i = 0;

        }

        ImGui::End();
    }
    void ContentBrowserPanel::Setup()
    {

            int my_image_width = 0;
            int my_image_height = 0;
            bool ret;
            ret = LoadTextureFromFile("E:\\VisualProjects\\TeraPlay\\Engine\\Resources\\TP_CP\\ImageIcon.png", &Content_Items_texture[0], &my_image_width, &my_image_height);
            ret = LoadTextureFromFile("E:\\VisualProjects\\TeraPlay\\Engine\\Resources\\TP_CP\\DirectoryIcon.png", &Content_Items_texture[1], &my_image_width, &my_image_height);
            ret = LoadTextureFromFile("E:\\VisualProjects\\TeraPlay\\Engine\\Resources\\TP_CP\\OBJIcon.png", &Content_Items_texture[2], &my_image_width, &my_image_height);
        
    }
}