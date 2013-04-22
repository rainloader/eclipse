/*
 * CTManager.cpp
 *
 *  Created on: 2013. 4. 16.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "CTManager.h"
#include <iostream>
#include <process.h>
#include <windows.h>


CTManager::CTManager() {
	// TODO Auto-generated constructor stub

}

CTManager::~CTManager() {
	// TODO Auto-generated destructor stub
}

void CTManager::start(){
	/* put inputha */
	HANDLE hThread = (HANDLE) _beginthreadex(NULL, 0, mInputHandler.receiveInput, NULL, 0, NULL);


	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
}
