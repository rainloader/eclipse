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
	DWORD getPeriod();

	void startThread();
	void finishThread();

	static UINT WINAPI runThread(LPVOID p);
	void run();

protected:

	void alarm();
	DWORD mPeriod;
	DWORD mGameStartTime;
	Notifiable* callee_;

	HANDLE hThread;
};


#endif /* TICKCOUNTER_H_ */
