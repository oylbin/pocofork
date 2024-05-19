#pragma once

#include <string>


#ifdef _WIN32
#if defined(BUILD_SHARED_LIBS) && defined(EXAMPLE_EXPORTS)
#define EXAMPLE_API __declspec(dllexport)
#elif defined(BUILD_SHARED_LIBS)
#define EXAMPLE_API __declspec(dllimport)
#else
#define EXAMPLE_API
#endif
#else
#define EXAMPLE_API
#endif

EXAMPLE_API std::string generateRandomString(size_t length);