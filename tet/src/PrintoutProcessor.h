/*
 * PrintoutProcessor.h
 *
 *  Created on: 2013. 4. 23.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef PRINTOUTPROCESSOR_H_
#define PRINTOUTPROCESSOR_H_

#include "MapData.h"
#include "Block.h"
#include <windows.h>

class PrintoutProcessor {
public:
	PrintoutProcessor();
	~PrintoutProcessor();
	void printPlayMap(MapData* pData, Block* pBlock);
	void clearConsole();
protected:
	void gotoxy(int x, int y);

private:
	/* play ui */
	static COORD M_UI_PLAY_MAP;
	//const char M_UI_PLAY_MAP_HEIGHT = 5;


};

#endif /* PRINTOUTPROCESSOR_H_ */
