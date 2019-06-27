//
// CHOCOVIRUS VI
// (C) 2019 modeco80 and CHOCOLATEMAN.
//
// File:
//		main.cc
//
// Description:
//		Main source file.
//


#include <Common.hh>
#include <PayloadMan.hh>

#include "RunOnce.hh"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR CmdLine, int cmdShow) { 
#ifdef DEVELOPMENT
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CONOUT$", "w", stdout);
	SetConsoleTitle("CHOCOVIRUS VI++ Debug");
#endif

	RunOnce blocker("CHOCOFUCKED", []() {
		MessageBoxA(GetFocus(), "It's fucked it's over.", "FUUUUUUUUUUUUUUUUUUUUUCK", MB_OK|MB_ICONHAND);
	});


	return 0;
}
