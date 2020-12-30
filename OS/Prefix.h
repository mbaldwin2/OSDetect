#pragma once

#ifndef OS_PREFIX
#define OS_PREFIX

#ifdef __cplusplus
# define EXTERN_C extern "C"
# define BEGIN_C EXTERN_C {
# define END_C }
#else
# define EXTERN_C
# define BEGIN_C
# define END_C
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
# define WINDOWS_OS 1
# define LINUX_OS 0
# define APPLE_OS 0
# define UNIX_OS 0
#elif defined(__linux__)
# define WINDOWS_OS 0
# define LINUX_OS 1
# define APPLE_OS 0
# define UNIX_OS 0
#elif defined(__APPLE_CC__) || defined(__OSX__)
# define WINDOWS_OS 0
# define LINUX_OS 0
# define APPLE_OS 1
# define UNIX_OS 0
#endif

#include <string>

#if WINDOWS_OS
# ifdef API_EXPORT
#  define API __declspec(dllexport)
# else
#  define API __declspec(dllimport)
# endif
#elif LINUX_OS
# define API
#endif

#if WINDOWS_OS
# if defined(UNICODE) || defined(_UNICODE)
#  define UNICODE_DEFINED 1
# else
#  define UNICODE_DEFINED 0
# endif
#endif

namespace OS {
API std::string Name();
}

#endif // ending OS_PREFIX //