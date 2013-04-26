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
	mPBlock = new Block();
	mScore = 0;
	mLine = 0;
	mLevel = 1;
}

IngameProcessor::~IngameProcessor() {
	delete mPTickCounter;
	delete mPBlock;
}

void IngameProcessor::play(){
	system("cls");
	mPMapData->initialize();
	/**/mPTickCounter->setPeriod(300);//1000
	generateBlock();
	//timer set.
	while(1){
		mPPrintoutProcessor->printPlayMap(mPMapData, mPBlock);
		//mPInputHandler->receiveInput();
		//start timer count.
		mPTickCounter->startThread();
	}
}

void IngameProcessor::generateBlock(){
	srand(time(NULL));
	int blockType = rand();
	blockType = blockType % 7 + 1;
	mPBlock->init(blockType);
}

void IngameProcessor::notify(int callerType) {
	switch(callerType)
	{
	case NOTIFY_TICKCOUNTER :
		int result = moveBlock(MOVING_DIRECTION_DOWN);
		if(result != 0){
			//set the block and generate next block;
			writeBlockToMap();
			generateBlock();
			cout << "NEW PHASE";
		}
		mPPrintoutProcessor->printPlayMap(mPMapData, mPBlock);
	}
}

int IngameProcessor::moveBlock(short movingDirection){
	//MapData currentMap = *mPMapData;
	Block movedBlock = mPBlock->getMovedBlock(movingDirection);
	if(checkBlockCollision(movedBlock))
	{
		return 1;
	}
	mPBlock->move(movingDirection);
	return 0;
}

int IngameProcessor::rotateBlock(short rotatingDirection){
	Block rotatedBlock = mPBlock->getRotatedBlock(rotatingDirection);
	if(checkBlockCollision(rotatedBlock))
	{
		return 1;
	}
	mPBlock->rotate(rotatingDirection);
	return 0;
}

bool IngameProcessor::checkBlockCollision(Block block){
	short pointValue;
	MAPPOS blockPos;

	/**/
	for(int i=0; i<3; i++){
		blockPos = block.getPos(i);
		/* Wall Check */
		if(blockPos.X < 0 || blockPos.X >= MAP_WIDTH || blockPos.Y < 0 || blockPos.Y >= MAP_HEIGHT){
			return true;
		}

		/* Map Check */
		pointValue = mPMapData->getMapPoint(blockPos.X, blockPos.Y);
		if(pointValue != 0)
			return true;
	}
	return false;
}

void IngameProcessor::writeBlockToMap(){
	MAPPOS blockPos;
	for(int i=0; i<3; i++){
		blockPos = mPBlock->getPos(i);
		mPMapData->setMapPoint(blockPos.X, blockPos.Y, mPBlock->getType());
	}
}

