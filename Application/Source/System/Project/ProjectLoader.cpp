
#include "ProjectLoader.h"
using namespace std;
void ProjectLoader::loadproj()
{
	ifstream Loader;
	Loader.open(ProjPath.c_str() + ProjName + FileName);
}

void ProjectLoader::saveproj()
{
	filesystem::create_directory(ProjPath.c_str() + ProjName);
	ofstream TheFile(ProjPath.c_str() + ProjName);
}
