/*
 * IngameProcessor.cpp
 *
 *  Created on: 2013. 4. 25.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "IngameProcessor.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define MOVING_DIRECTION_LEFT 1
#define MOVING_DIRECTION_RIGHT 2
#define MOVING_DIRECTION_DOWN 3

using namespace std;

IngameProcessor::IngameProcessor(PrintoutProcessor* pPrintoutProcessor, InputHandler* pInputHandler, MapData* pMapData)
: mPPrintoutProcessor(pPrintoutProcessor), mPInputHandler(pInputHandler), mPMapData(pMapData) {
	mPTickCounter = new TickCounter(this);
	mBlock = new Block();
}

IngameProcessor::~IngameProcessor() {
	delete mPTickCounter;
	delete mBlock;
}

void IngameProcessor::play(){
	system("cls");
	mPMapData->initialize();
	mPTickCounter->setPeriod(1000);
	//timer set.
	while(1){
		//start timer count.


		mPPrintoutProcessor->printPlayMap(mPMapData);
		//mPInputHandler->receiveInput();
		mPTickCounter->startThread();
	}
}

void IngameProcessor::generateBlock(){
//	int blockType = srand(time(NULL));
	//blockType = blockType % 7 + 1;

}

void IngameProcessor::notify(int callerType) {
	switch(callerType)
	{
	case NOTIFY_TICKCOUNTER :
		moveBlock(MOVING_DIRECTION_DOWN);
		mPPrintoutProcessor->printPlayMap(mPMapData);
	}
}

void IngameProcessor::moveBlock(int movingDirection){
	MapData currentMap = *mPMapData;

	//MapData currentMap(mPMapData);
}


