#pragma once

//	Macro to build api or import dll

#ifdef FSL_BUILD_DLL
	#define	FOSSIL_API __declspec(dllexport)
#else
	#define	FOSSIL_API __declspec(dllimport)
#endif