#pragma once
#include<fstream>
#include <filesystem>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class ProjectLoader
{
public:
	string FileName = ProjName + Exten;
	string ProjName = "NewTPProject";
	string Exten = ".TPProj";
	string ProjPath = "C:\\Program Files\\UnkGames\\TeraPlay\\Projects";
	void loadproj();
	void saveproj();
	struct DirectoryFolders {
		string Assets = "assets";
		string Build = "build";
		string Game = "Game";
	};
};

