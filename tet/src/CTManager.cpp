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

using namespace std;


CTManager::CTManager() {
	// TODO Auto-generated constructor stub
}

CTManager::~CTManager() {
	// TODO Auto-generated destructor stub
}

void CTManager::start(){
	/* put inputha */
	//mInputHandlerThread = (HANDLE) _beginthreadex(NULL, 0, mInputHandler.receiveInputT, NULL, 0, NULL);
	title();
	//WaitForSingleObject(mInputHandlerThread, INFINITE);

}

void CTManager::title(){
	cout << "TITLE" << endl;
	cout << "Press Any Key" << endl;
	while(1){
		if(mInputHandler.receiveInput() != 0)
		{
			menu();
			break;
		}
	}
	end();
}

void CTManager::menu(){
	system("cls");
	cout << "MENU" << endl;
	char ch = mInputHandler.receiveInput();
	cout << ch << endl;
	play();
}

void CTManager::play(){
	system("cls");
	mData.initialize();
	//timer set.
	while(1){
		//start timer count.


		mPrintoutProcessor.printPlayMap(&(this->mData));
		mInputHandler.receiveInput();
	}

}

void CTManager::end(){
	closeThread();
}

void CTManager::drawMap(){

}

void CTManager::closeThread(){
	//CloseHandle(mInputHandlerThread);
}
