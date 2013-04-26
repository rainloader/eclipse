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


using namespace std;

IngameProcessor::IngameProcessor(PrintoutProcessor* pPrintoutProcessor, InputHandler* pInputHandler, MapData* pMapData)
: mPPrintoutProcessor(pPrintoutProcessor), mPInputHandler(pInputHandler), mPMapData(pMapData) {
	mPTickCounter = new TickCounter(this);
	mBlock = new Block();
	mScore = 0;
	mLine = 0;
	mLevel = 1;
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
	srand(time(NULL));
	int blockType = rand();
	blockType = blockType % 7 + 1;
	mBlock->setType(blockType);
}

void IngameProcessor::notify(int callerType) {
	switch(callerType)
	{
	case NOTIFY_TICKCOUNTER :
		moveBlock(MOVING_DIRECTION_DOWN);
		mPPrintoutProcessor->printPlayMap(mPMapData);
	}
}

int IngameProcessor::moveBlock(short movingDirection){
	MapData currentMap = *mPMapData;
	Block movedBlock = mBlock->getMovedBlock(movingDirection);
	if(blockCollisionCheck(movedBlock))
	{
	//	mBlock->move()
	}
	return 0;
	//MapData currentMap(mPMapData);
}


bool IngameProcessor::blockCollisionCheck(Block block){
	short pointValue;
	MAPPOS blockPos;
	for(int i=0; i<3; i++){
		blockPos = block.getPos(i);
		pointValue = mPMapData->getMapPoint(blockPos.X, blockPos.Y);
		if(pointValue != 0)
			return true;
	}
	return false;
}

