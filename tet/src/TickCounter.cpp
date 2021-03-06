/*
 * TickCounter.cpp
 *
 *  Created on: 2013. 4. 24.
 *      Author: �÷������
 */

#include "TickCounter.h"
#include <process.h>
#include <Windows.h>
#pragma comment(lib, "winmm.lib")

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
	mHThread = (HANDLE) _beginthreadex(NULL, 0, runThread, (LPVOID)this, 0, NULL);
	//WaitForSingleObject(mHThread, INFINITE);
}

void TickCounter::finishThread(){
	CloseHandle(mHThread);
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
