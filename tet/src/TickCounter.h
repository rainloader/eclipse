/*
 * TickCounter.h
 *
 *  Created on: 2013. 4. 24.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef TICKCOUNTER_H_
#define TICKCOUNTER_H_

//#include "delegate.h"

class TickCounter {
public:
	//typedef Delegate0<void> Callback;

	TickCounter();
	//TickCounter(Callback callback);
	~TickCounter();
	void setPeriod(int period);
	void run();
	void alarm();
protected:
	int mPeriod;
//Callback callback_;
};

#endif /* TICKCOUNTER_H_ */
