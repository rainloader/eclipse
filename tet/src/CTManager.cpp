/*
 * CTManager.cpp
 *
 *  Created on: 2013. 4. 16.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "CTManager.h"
#include <process.h>
#include <windows.h>


CTManager::CTManager() {
	mPInputHandler = new InputHandler(this);
	mPPrintoutProcessor = new PrintoutProcessor();
	mPTickCounter = new TickCounter(this);
	mPIngameProcessor = new IngameProcessor(mPPrintoutProcessor, mPInputHandler);
	mRunningState = s_title;
}

CTManager::~CTManager() {
	delete mPIngameProcessor;
	delete mPTickCounter;
	delete mPInputHandler;
	delete mPPrintoutProcessor;
}

void CTManager::start(){
	/* put inputha */
	//title();
	runState();
}

void CTManager::runState(){
	while(mRunningState != s_end){
		switch (mRunningState){
			case s_title:
				title();
				break;
			case s_menu:
				menu();
				break;
			case s_play:
				play();
				break;
			default:
				break;
		}
	}
}

void CTManager::title(){
	mPPrintoutProcessor->clearConsole();
	mPPrintoutProcessor->printTitle();
	while(1){
		if(mPInputHandler->receiveInput() != 0)
		{
			mRunningState = s_menu;
			break;
		}
	}
}

void CTManager::menu(){
	mPPrintoutProcessor->clearConsole();
	mPPrintoutProcessor->printMenu();
	char ch = mPInputHandler->receiveInput();
	mRunningState = s_play;
}

void CTManager::play(){
	mPPrintoutProcessor->clearConsole();
	mPIngameProcessor->play();
	mRunningState = s_end;
}

void CTManager::notify(int callerType){

}
