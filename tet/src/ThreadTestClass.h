/*
 * ThreadTestClass.h
 *
 *  Created on: 2013. 4. 22.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef THREADTESTCLASS_H_
#define THREADTESTCLASS_H_

#include <windows.h>

class ThreadTestClass {
public:
	ThreadTestClass();
	~ThreadTestClass();
	static UINT WINAPI threadProc(LPVOID p);
	void start();
};

#endif /* THREADTESTCLASS_H_ */
