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
	mPInputHandler = new InputHandler();
	mPPrintoutProcessor = new PrintoutProcessor();
	mPTickCounter = new TickCounter(this);
	mPData = new MapData();
	mPIngameProcessor = new IngameProcessor(mPPrintoutProcessor, mPInputHandler, mPData);
}

CTManager::~CTManager() {

	delete mPIngameProcessor;
	delete mPData;
	delete mPTickCounter;
	delete mPInputHandler;
	delete mPPrintoutProcessor;
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
		if(mPInputHandler->receiveInput() != 0)
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
	char ch = mPInputHandler->receiveInput();
	cout << ch << endl;
	play();
}

void CTManager::play(){
	mPIngameProcessor->play();
}

void CTManager::notify(int callerType){
	if(callerType == NOTIFY_TICKCOUNTER){
		//down block

		//if(space below) -> down

		//else(no space) -> next block

		/**/cout << "!!";
	}
}


void CTManager::moveBlock(int movingDirection){

}

void CTManager::rotateBlock(int rotatingDirection){

}

void CTManager::end(){
	closeThread();
}

void CTManager::drawMap(){

}

void CTManager::closeThread(){
	//CloseHandle(mInputHandlerThread);
}
