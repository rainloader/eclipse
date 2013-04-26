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
	void rotateBlock(short rotatingDirection);

	bool blockCollisionCheck(Block block);


	PrintoutProcessor* mPPrintoutProcessor;
	InputHandler* mPInputHandler;
	TickCounter* mPTickCounter;

	MapData* mPMapData;
	Block* mBlock;

	int mScore;
	int mLine;
	int mLevel;

};

#endif /* INGAMEPROCESSOR_H_ */
