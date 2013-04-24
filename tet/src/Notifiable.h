/*
 * Notifiable.h
 *
 *  Created on: 2013. 4. 24.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef NOTIFIABLE_H_
#define NOTIFIABLE_H_

#define NOTIFY_TICKCOUNTER 1


class Notifiable {
public:
	virtual void notify(int callerType) = 0;
};

#endif
