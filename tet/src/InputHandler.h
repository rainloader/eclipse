/*
 * InputHandler.h
 *
 *  Created on: 2013. 4. 16.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include <windows.h>

class InputHandler {
public:
	InputHandler();
	~InputHandler();
	static UINT WINAPI receiveInput(LPVOID p);
};

#endif /* INPUTHANDLER_H_ */
