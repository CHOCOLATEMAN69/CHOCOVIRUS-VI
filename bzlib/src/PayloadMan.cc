//
// Blitz
// (C) 2019 modeco80.
//
// File:
//		PayloadMan.cc
//
// Description:
//		Payload manager implmentation
//

#include <PayloadMan.hh>


namespace Blitz {
	namespace PayloadMan {
		DWORD WINAPI InternalWorker(LPVOID param) {
			BasePayload* payload = (BasePayload*)param;
			while(payload->Condition() != true) Sleep(16);

			while(true) {
				payload->Work();
				payload->m_Ticks++;
				Sleep(16);
			}
			return 0;
		}

		void StartPayload(BasePayload* payload) {
			if(payload == NULL) return;
			payload->m_hThread = CreateThread(NULL, 0, &PayloadMan::InternalWorker, (LPVOID)payload, 0, NULL);
		}
	}

}
