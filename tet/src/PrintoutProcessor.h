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
	void printPlayUI();
	void printPlayMap(MapData* pData, Block* pBlock);
	void printNextBlock(Block* pNextBlock);
	void clearConsole();
protected:
	void gotoxy(int x, int y);

private:
	/* play ui */
	const COORD M_UI_PLAY_MAP = {2,1};
	const COORD M_UI_NEXT_BLOCK = {30,3};
	//const char M_UI_PLAY_MAP_HEIGHT = 5;


};

#endif /* PRINTOUTPROCESSOR_H_ */
