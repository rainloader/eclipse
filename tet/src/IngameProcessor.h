/*
 * IngameProcessor.h
 *
 *  Created on: 2013. 4. 25.
 *      Author: �÷������
 */

#ifndef INGAMEPROCESSOR_H_
#define INGAMEPROCESSOR_H_

#include "Notifiable.h"
#include "PrintoutProcessor.h"
#include "InputHandler.h"
#include "TickCounter.h"
#include "MapData.h"
#include "Block.h"

class IngameProcessor : protected Notifiable {
public:
	IngameProcessor(PrintoutProcessor* pPrintoutProcessor, InputHandler* pInputHandler);
	~IngameProcessor();
	void play();

protected:
	void notify(int callerType);

	void generateBlock();
	int moveBlock(short movingDirection);
	int rotateBlock(short rotatingDirection);

	void afterBlockDropped();

	bool checkGameOver();
	void calculateScoreAndLevel(int clearedLine);
	int checkLineFilled();
	void clearLine(int lineNumber);
	bool checkBlockCollision(Block block);
	void writeBlockToMap();

	PrintoutProcessor* mPPrintoutProcessor;
	InputHandler* mPInputHandler;
	TickCounter* mPTickCounter;

	MapData* mPMapData;
	Block* mPBlock;
	Block* mPNextBlock;

	bool isNotificationLocked;
	bool isGameOvered;

	int mScore;
	int mLine;
	int mLevel;

};

#endif /* INGAMEPROCESSOR_H_ */
