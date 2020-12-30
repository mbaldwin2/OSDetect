#pragma once

#ifndef OS_ENVIRONMENT
#define OS_ENVIRONMENT

#include <OS/Prefix.h>

#include <vector>
#include <map>

namespace OS {

	namespace System {

		class Environment {
		public:
			Environment();
			~Environment();

			bool AddItem(const std::string &);
			bool RemoveItem(const std::string &);
			bool Update();

			std::string & operator [] (const std::string &);
			const std::string & operator [] (const std::string &) const;

			bool operator == (const Environment &) const;
			bool operator != (const Environment &) const;
			Environment & operator = (const Environment &);
			Environment & operator = ( const std::map<std::string, std::string> & );
		protected:
			std::vector< std::string > env;
		};

	}
	
}

#endif // ending OS_ENVIRONMENT //