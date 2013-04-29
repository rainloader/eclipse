/*
 * IngameProcessor.cpp
 *
 *  Created on: 2013. 4. 25.
 *      Author: �÷������
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
	/**/mPTickCounter->setPeriod(200);//1000
	generateBlock();
	mPInputHandler->startThread();
	mPTickCounter->startThread();
	//timer set.
	while(1){
		/*mPPrintoutProcessor->printPlayMap(mPMapData, mPBlock);
		//mPInputHandler->receiveInput();
		//start timer count.*/

	}
}

void IngameProcessor::generateBlock(){
	srand(time(NULL));
	int blockType = rand();
	blockType = blockType % 7 + 1;
	mPBlock->init(blockType);
}

void IngameProcessor::notify(int callerType) {
	while(isNotificationLocked){
		/**/cout << "Locked" << endl;
	}
	isNotificationLocked = true;
	switch(callerType)
	{
	case NOTIFY_TICKCOUNTER:
	{
		int result = moveBlock(MOVING_DIRECTION_DOWN);
		if(result != 0){
			//set the block and generate next block;
			writeBlockToMap();
			generateBlock();
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
			writeBlockToMap();
			generateBlock();
		}
		break;
	}
	case NOTIFY_INPUT_1P_DROP:
	{
		//TODO : drop
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

