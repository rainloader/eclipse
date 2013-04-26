/*
 * PrintoutProcessor.cpp
 *
 *  Created on: 2013. 4. 23.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "PrintoutProcessor.h"

#include <iostream>
#include <unistd.h>
#include <stdio.h>

using namespace std;

PrintoutProcessor::PrintoutProcessor() {
	// TODO Auto-generated constructor stub
	//M_UI_PLAY_MAP = {5, 5};
}

PrintoutProcessor::~PrintoutProcessor() {
	// TODO Auto-generated destructor stub
}

void PrintoutProcessor::printPlayMap(MapData* pData, Block* pBlock){
	//cout << "printmap" << endl;
	std::string input;
	short mapPoint;
	MAPPOS blockPosArray[4];

	for(int k=0; k<4; k++){
		blockPosArray[k] = pBlock->getPos(k);
	}

	for(int i=0; i<MAP_WIDTH; i++){
		for(int j=2; j<MAP_HEIGHT; j++){
			//upper 2 is hidden area
			gotoxy(i*2, j);

			mapPoint = pData->getMapPoint(i, j);
			for(int k=0; k<4; k++){
				if(blockPosArray[k].X == i && blockPosArray[k].Y == j)
				{
					mapPoint = pBlock->getType();
					break;
				}
			}

			switch(mapPoint){
			case 0:
				cout << "  ";
				break;
			case 1:
				cout << "¡á";
				break;
			case 2:
				cout << "¨è";
				break;
			case 3:
				cout << "¨é";
				break;
			case 4:
				cout << "¨ê";
				break;
			case 5:
				cout << "¨ë";
				break;
			case 6:
				cout << "¨ì";
				break;
			case 7:
				cout << "¨í";
				break;
			default:
				cout << "??";
				break;
			}
		}
	}
}

void PrintoutProcessor::gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
