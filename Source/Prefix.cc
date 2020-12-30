#define EXPORT __declspec(dllexport)
#include <OS/Prefix.h>

namespace OS {
	EXPORT std::string Name() {
# if WINDOWS_OS
		return "Microsoft";
# elif LINUX_OS
		return "Linux";
# elif APPLE_OS
		return "Apple";
# endif
	}
}