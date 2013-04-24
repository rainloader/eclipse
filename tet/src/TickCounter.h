/*
 * TickCounter.h
 *
 *  Created on: 2013. 4. 24.
 *      Author: �÷������
 */

#ifndef TICKCOUNTER_H_
#define TICKCOUNTER_H_

#include "Notifiable.h"

class TickCounter {
public:
	TickCounter(Notifiable* callee_);
	~TickCounter();
	void setPeriod(int period);
	void run();
	void alarm();

protected:
	int mPeriod;
	Notifiable* callee_;
};

#endif /* TICKCOUNTER_H_ */
