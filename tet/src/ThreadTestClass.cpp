/*
 * ThreadTestClass.cpp
 *
 *  Created on: 2013. 4. 22.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "ThreadTestClass.h"
#include <iostream>
#include <process.h>
#include <windows.h>

using namespace std;

ThreadTestClass::ThreadTestClass() {
	// TODO Auto-generated constructor stub

}

ThreadTestClass::~ThreadTestClass() {
	// TODO Auto-generated destructor stub
}

UINT WINAPI ThreadTestClass::threadProc(LPVOID p) {
	for(int i=0; ; i++){
		cout << "ThreadProc : " << i << endl;
		//Thread::sleep(1);
	}
	return 0;
}

void ThreadTestClass::start() {
	HANDLE hThread = (HANDLE) _beginthreadex(NULL, 0, threadProc, (LPVOID)this, 0, NULL);


	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
}
