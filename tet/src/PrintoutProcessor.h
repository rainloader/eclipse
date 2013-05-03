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
	void printTitle();
	void printMenu();
	void printPlayUI();
	void printPlayMap(MapData* pData, Block* pBlock);
	void printNextBlock(Block* pNextBlock);
	void printPlayData(int score, int line, int level);
	void clearConsole();
protected:
	void gotoxy(int x, int y);
	void setColor(int color, int bgcolor);
	int _drgb ( bool d, bool r, bool g, bool b);
private:
	/* play ui */
	COORD M_UI_PLAY_MAP;
	COORD M_UI_NEXT_BLOCK;
	COORD M_UI_PLAY_DATA;
	//const char M_UI_PLAY_MAP_HEIGHT = 5;


};

#endif /* PRINTOUTPROCESSOR_H_ */

