/*
 * IngameProcessor.h
 *
 *  Created on: 2013. 4. 25.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
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
	IngameProcessor(PrintoutProcessor* pPrintoutProcessor, InputHandler* pInputHandler, MapData* pData);
	~IngameProcessor();
	void play();

protected:
	void notify(int callerType);

	void generateBlock();
	int moveBlock(short movingDirection);
	int rotateBlock(short rotatingDirection);

	bool checkBlockCollision(Block block);
	void writeBlockToMap();


	PrintoutProcessor* mPPrintoutProcessor;
	InputHandler* mPInputHandler;
	TickCounter* mPTickCounter;

	MapData* mPMapData;
	Block* mPBlock;

	bool isNotificationLocked;

	int mScore;
	int mLine;
	int mLevel;

};

#endif /* INGAMEPROCESSOR_H_ */
