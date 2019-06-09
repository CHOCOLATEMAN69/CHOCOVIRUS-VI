//
// Blitz
// (C) 2019 modeco80.
//
// File:
//		PayloadMan.c
//
// Description:
//		Implementation of the payload manager.
//

#include "PayloadMan.h"

DWORD WINAPI BlitzInternalPayloadThread(LPVOID ThreadParam) {
	BlitzPayload* Payload = (BlitzPayload*)ThreadParam;
	if (Payload == NULL) return 1; // ?Que?

	// We have made it this far.
	// Announce a message on debug builds then poll until the condition test
	// returns TRUE
	BLITZ_DEBUG_LOG("Initalizing \"%s\"", Payload->Name);
	while ((Payload->ConditionTest((void*)Payload)) != TRUE) Sleep(1000);

	BLITZ_DEBUG_LOG("Starting \"%s\"", Payload->Name);
	// Construct and start the payload.
	Payload->Ctor((void*)Payload);

	while (1) {
		Payload->Work((void*)Payload);
		Sleep(BLITZ_PAYLOAD_TICK_MS);
		++Payload->Ticks;
	}
}

HANDLE WINAPI BlitzInitalizePayload(BlitzPayload* Payload) {
	return CreateThread(NULL, 0, BlitzInternalPayloadThread, (LPVOID)Payload, 0, NULL);
}