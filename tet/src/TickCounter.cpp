/*
 * TickCounter.cpp
 *
 *  Created on: 2013. 4. 24.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "TickCounter.h"
#include <process.h>

TickCounter::TickCounter(Notifiable* callee) : callee_(callee) {
	setPeriod(1000);
}

TickCounter::~TickCounter() {
}

void TickCounter::setPeriod(DWORD period){
	this->mPeriod = period;
}

DWORD TickCounter::getPeriod(){
	return this->mPeriod;
}

void TickCounter::startThread(){
	hThread = (HANDLE) _beginthreadex(NULL, 0, runThread, (LPVOID)this, 0, NULL);
	WaitForSingleObject(hThread, INFINITE);
}

void TickCounter::finishThread(){
	CloseHandle(hThread);
}

UINT WINAPI TickCounter::runThread(LPVOID p){
	TickCounter* pTickCounter  = (TickCounter*) p;

	pTickCounter->run();
	return 0;
}

void TickCounter::run(){
	DWORD mGameStartTime = timeGetTime();

	while(1){
		DWORD periodStartTime = timeGetTime();
		while(1){
			DWORD periodElapsedTime = timeGetTime() - periodStartTime;
			if(periodElapsedTime >= mPeriod){
				alarm();
				break;
			}
		}
	}
}



void TickCounter::alarm(){
	callee_->notify(NOTIFY_TICKCOUNTER);
}
