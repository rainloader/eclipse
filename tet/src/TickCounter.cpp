/*
 * TickCounter.cpp
 *
 *  Created on: 2013. 4. 24.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "TickCounter.h"
//#include <Mmsystem.h>

TickCounter::TickCounter(Notifiable* callee) : callee_(callee) {
	setPeriod(1000);
}

TickCounter::~TickCounter() {
}

void TickCounter::setPeriod(DWORD period){
	this->mPeriod = period;
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
