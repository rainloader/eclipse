/*
 * TickCounter.cpp
 *
 *  Created on: 2013. 4. 24.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "TickCounter.h"
#include "time.h"

TickCounter::TickCounter(Notifiable* callee) : callee_(callee) {
	// TODO Auto-generated constructor stub
	mPeriod = 1000;
}

TickCounter::~TickCounter() {
	// TODO Auto-generated destructor stub

}

void TickCounter::setPeriod(int period){
	this->mPeriod = period;
}

void TickCounter::run(){

}

void TickCounter::alarm(){
	callee_->notify(NOTIFY_TICKCOUNTER);
}
