#pragma once

#ifdef TP_PLATFORM_WINDOWS
    #ifdef TP_BUILD_DLL
            #define TP_API __declspec(dllexport)
    #else 
            #define TP_API __declspec(dllimport)
    #endif // TP_BUILD_DLL
#else
#error TeraPlay Running with windows!

#endif // TP_PLATFORM_WINDOWS
