#pragma once
#include <filesystem>

#include<vector>
namespace TeraPlay {
    class ContentBrowserPanel
    {
    public:
        ContentBrowserPanel();
        void OnImGuiRender();
        void Setup();
        GLuint DirectoryIcon = 0;
    private:
        std::filesystem::path m_CurrentDirectory;
    };


}