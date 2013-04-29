/*
 * Notifiable.h
 *
 *  Created on: 2013. 4. 24.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef NOTIFIABLE_H_
#define NOTIFIABLE_H_

#define NOTIFY_TICKCOUNTER 1
#define NOTIFY_INPUT_1P_LEFT 2
#define NOTIFY_INPUT_1P_RIGHT 3
#define NOTIFY_INPUT_1P_DOWN 4
#define NOTIFY_INPUT_1P_DROP 5
#define NOTIFY_INPUT_1P_ROTATE_CW 6
#define NOTIFY_INPUT_1P_ROTATE_CCW 7
#define NOTIFY_INPUT_2P_LEFT 12
#define NOTIFY_INPUT_2P_RIGHT 13
#define NOTIFY_INPUT_2P_DOWN 14
#define NOTIFY_INPUT_2P_DROP 15
#define NOTIFY_INPUT_2P_ROTATE_CW 16
#define NOTIFY_INPUT_2P_ROTATE_CCW 17



class Notifiable {
public:
	virtual void notify(int callerType) = 0;
};

#endif
