/*
 * InputHandler.h
 *
 *  Created on: 2013. 4. 16.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include "Notifiable.h"
#include <windows.h>

class InputHandler {
public:
	InputHandler(Notifiable* callee_);
	~InputHandler();

	void startThread();
	void finishThread();
	void switchCallee(Notifiable* callee_);

	static UINT WINAPI receiveInputT(LPVOID p);
	char receiveInput();
	void setKeyStat(char key);
	char getKeyStat();
protected:
	static UINT WINAPI runThread(LPVOID p);
	void run();
	void passInput(int callerInputType);
	char receiveInputThread(LPVOID p);
	char keyStat;

	Notifiable* mCallee_;
	HANDLE mHThread;
};

#endif /* INPUTHANDLER_H_ */
