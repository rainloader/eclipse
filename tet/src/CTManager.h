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
#include "Data.h"

class CTManager {
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

	void drawMap();


	InputHandler mInputHandler;
	PrintoutProcessor mPrintoutProcessor;
	//HANDLE mInputHandlerThread;
	Data data;
private:
};

#endif /* CTMANAGER_H_ */
