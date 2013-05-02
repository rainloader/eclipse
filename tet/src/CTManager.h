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

enum State{s_title, s_menu, s_play, s_end};

class CTManager : protected Notifiable {
public:
	CTManager();
	~CTManager();

	void start();
	void end();
protected:
	void runState();
	void title();
	void menu();
	void play();

	void notify(int callerType);

	PrintoutProcessor* mPPrintoutProcessor;
	InputHandler* mPInputHandler;
	IngameProcessor* mPIngameProcessor;
	TickCounter* mPTickCounter;
	MapData* mPData;
	State mRunningState;
private:
};

#endif /* CTMANAGER_H_ */
