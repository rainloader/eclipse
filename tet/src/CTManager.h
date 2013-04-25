/*
 * CTManager.h
 *
 *  Created on: 2013. 4. 16.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef CTMANAGER_H_
#define CTMANAGER_H_

#include "InputHandler.h"
#include "PrintoutProcessor.h"
#include "IngameProcessor.h"
#include "MapData.h"
#include "TickCounter.h"
#include "Notifiable.h"

class CTManager : protected Notifiable {
public:
	CTManager();
	~CTManager();

	void start();
	void end();
protected:
	void closeThread();
	void title();
	void menu();
	void play();

	void notify(int callerType);

	void drawMap();

	void moveBlock(int movingDirection);
	void rotateBlock(int rotatingDirection);

	PrintoutProcessor* mPPrintoutProcessor;
	InputHandler* mPInputHandler;

	IngameProcessor* mPIngameProcessor;

	TickCounter* mPTickCounter;
	//HANDLE mInputHandlerThread;
	MapData* mPData;
private:
};

#endif /* CTMANAGER_H_ */
