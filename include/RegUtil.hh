//
// Blitz
// (C) 2019 modeco80.
//
// File:
//		RegUtil.cc
//
// Description:
//		TODO(modeco80)
//

#include <Common.hh>


namespace Blitz {
	namespace Registry {
		void WINAPI WriteString(HKEY Base, const char* Subkey, const char* ValueName, char* Value);
		void WINAPI WriteDword(HKEY Base, const char* Subkey, const char* ValueName, DWORD Value);
	}
}
