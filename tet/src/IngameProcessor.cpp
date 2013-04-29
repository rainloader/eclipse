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
	mPInputHandler = new InputHandler(this);
	mPBlock = new Block();
	isNotificationLocked = false;
	isGameOvered = false;
	mScore = 0;
	mLine = 0;
	mLevel = 1;
	srand(time(NULL));
}

IngameProcessor::~IngameProcessor() {
	delete mPTickCounter;
	delete mPBlock;
}

void IngameProcessor::play(){
	system("cls");
	mPMapData->initialize();
	/**/mPTickCounter->setPeriod(1000);//1000
	isNotificationLocked = false;
	isGameOvered = false;
	generateBlock();
	mPInputHandler->startThread();
	mPTickCounter->startThread();

	//timer set.
	while(1){
		/*mPPrintoutProcessor->printPlayMap(mPMapData, mPBlock);
		//mPInputHandler->receiveInput();
		//start timer count.*/
		if(isGameOvered)
			break;
	}
	mPInputHandler->finishThread();
	mPTickCounter->finishThread();
	//mPPrintoutProcessor->clearConsole();
	cout << "Game Over";
}

void IngameProcessor::generateBlock(){
	int blockType = rand();
	blockType = blockType % 7 + 1;
	mPBlock->init(blockType);
}

void IngameProcessor::notify(int callerType) {
	while(isNotificationLocked){
		if(isGameOvered)
			return;
	}
	isNotificationLocked = true;
	switch(callerType)
	{
	case NOTIFY_TICKCOUNTER:
	{
		int result = moveBlock(MOVING_DIRECTION_DOWN);
		if(result != 0){
			//set the block and generate next block;
			afterBlockDropped();
		}
		break;
	}
	case NOTIFY_INPUT_1P_LEFT:
	{
		moveBlock(MOVING_DIRECTION_LEFT);
		break;
	}
	case NOTIFY_INPUT_1P_RIGHT:
	{
		moveBlock(MOVING_DIRECTION_RIGHT);
		break;
	}
	case NOTIFY_INPUT_1P_DOWN:
	{
		int result = moveBlock(MOVING_DIRECTION_DOWN);
		if(result != 0){
			//set the block and generate next block;
			afterBlockDropped();
		}
		break;
	}
	case NOTIFY_INPUT_1P_DROP:
	{
		int result = 0;
		while(result == 0){
			result = moveBlock(MOVING_DIRECTION_DOWN);
		}
		afterBlockDropped();
		break;
	}
	case NOTIFY_INPUT_1P_ROTATE_CW:
	{
		rotateBlock(ROTATING_DIRECTION_CLOCKWISE);
		break;
	}
	case NOTIFY_INPUT_1P_ROTATE_CCW:
	{
		rotateBlock(ROTATING_DIRECTION_COUNTERCLOCK);
		break;
	}
	default:
	{
		break;
	}
	}
	mPPrintoutProcessor->printPlayMap(mPMapData, mPBlock);
	isNotificationLocked = false;
}

int IngameProcessor::moveBlock(short movingDirection){
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

void IngameProcessor::afterBlockDropped(){
		//set the block and generate next block;
		writeBlockToMap();
		checkLineFilled();
		generateBlock();
		if(checkGameOver()){
			isGameOvered = true;
		}
}

bool IngameProcessor::checkGameOver(){
	if(checkBlockCollision(*mPBlock))
		return true;
	return false;
}

void IngameProcessor::checkLineFilled(){
	bool isLineFilled;
	for(int j=0; j<MAP_HEIGHT; j++){
		isLineFilled = true;
		for(int i=0; i<MAP_WIDTH; i++){
			if(mPMapData->getMapPoint(i, j) == 0){
				isLineFilled = false;
				break;
			}
		}
		if(isLineFilled)
			clearLine(j);
	}
}

void IngameProcessor::clearLine(int lineNumber){
	/* first, clear line */
	for(int i=0; i<MAP_WIDTH; i++){
		mPMapData->setMapPoint(i, lineNumber, 8);
		mPPrintoutProcessor->printPlayMap(mPMapData, mPBlock);
	}

	short pointData;
	/* second, drop upper lines */
	for(int j=lineNumber-1; j>=0; j--){
		for(int i=0; i<MAP_WIDTH; i++){
			pointData = mPMapData->getMapPoint(i, j);
			mPMapData->setMapPoint(i, j+1, pointData);
		}
	}
}

bool IngameProcessor::checkBlockCollision(Block block){
	short pointValue;
	MAPPOS blockPos;

	for(int i=0; i<4; i++){
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
	for(int i=0; i<4; i++){
		blockPos = mPBlock->getPos(i);
		mPMapData->setMapPoint(blockPos.X, blockPos.Y, mPBlock->getType());
	}
}
