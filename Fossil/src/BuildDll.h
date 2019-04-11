#pragma once

//	Macro to build api or import dll

#ifdef FSL_BUILD_DLL
	#define	FSL_API __declspec(dllexport)
#else
	#define	FSL_API __declspec(dllimport)
#endif