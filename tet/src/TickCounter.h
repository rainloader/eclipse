/*
 * TickCounter.h
 *
 *  Created on: 2013. 4. 24.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef TICKCOUNTER_H_
#define TICKCOUNTER_H_

#include <windows.h>
#include "Notifiable.h"

class TickCounter {
public:
	TickCounter(Notifiable* callee_);
	~TickCounter();
	void setPeriod(DWORD period);
	void run();
	void alarm();

protected:
	DWORD mPeriod;
	DWORD mGameStartTime;
	Notifiable* callee_;
};


#endif /* TICKCOUNTER_H_ */
