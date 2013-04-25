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
	void moveBlock(int movingDirection);
	void rotateBlock(int rotatingDirection);


	PrintoutProcessor* mPPrintoutProcessor;
	InputHandler* mPInputHandler;
	TickCounter* mPTickCounter;

	MapData* mPMapData;
	Block* mBlock;

	int score;
	int line;
	int level;

};

#endif /* INGAMEPROCESSOR_H_ */
