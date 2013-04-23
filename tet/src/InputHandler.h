/*
 * InputHandler.h
 *
 *  Created on: 2013. 4. 16.
 *      Author: �÷������
 */

#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include <windows.h>

class InputHandler {
public:
	InputHandler();
	~InputHandler();
	static UINT WINAPI receiveInputT(LPVOID p);
	char receiveInput();
	void setKeyStat(char key);
	char getKeyStat();
protected:
	char keyStat;
};

#endif /* INPUTHANDLER_H_ */
