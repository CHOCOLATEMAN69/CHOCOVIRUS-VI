//
// Blitz
// (C) 2019 modeco80.
//
// File:
//		PayloadMan.hh
//
// Description:
//		Payload manager defs
//
#pragma once

#include <Common.hh>

namespace Blitz {

class BasePayload {
public:
	inline BasePayload() {
		m_Ticks = 0;
	}
	virtual ~BasePayload() {}

	virtual bool Condition() = 0;
	virtual void Work() = 0;

	unsigned long long m_Ticks;
	HANDLE m_hThread;
};

	namespace PayloadMan {
		void StartPayload(BasePayload* payload);
	}

}
