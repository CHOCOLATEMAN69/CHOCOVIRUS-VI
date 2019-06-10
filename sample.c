//
// CHOCOVIRUS VI
// (C) 2019 modeco80 and CHOCOLATEMAN.
//
// File:
//		sample.c
//
// Description:
//		Sample payload
//

#include "Common.h"
#include "PayloadMan.h"
#include "RegUtil.h"


BOOL Cond_Sample(void* This) {
	return TRUE;
}

void Init_Sample(void* This) {
	// Do something that only needs to be run once.
}

void Work_Sample(void* This) {
	// Do something that needs to be run repeatedly.
}

BlitzPayload Sample = {
	"Sample",
	Cond_Sample,
	Init_Sample,
	Work_Sample
};