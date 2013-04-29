/*
 * PrintoutProcessor.cpp
 *
 *  Created on: 2013. 4. 23.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "PrintoutProcessor.h"

#include <iostream>

#include <stdio.h>

using namespace std;

PrintoutProcessor::PrintoutProcessor() {
	// TODO Auto-generated constructor stub
	//M_UI_PLAY_MAP = {5, 5};
}

PrintoutProcessor::~PrintoutProcessor() {
	// TODO Auto-generated destructor stub
}

void PrintoutProcessor::printPlayUI(){
	/* print play map ui */
	for(int i=0; i<MAP_WIDTH+2; i++){
		for(int j=0; j<MAP_HEIGHT; j++){
			gotoxy(i*2 + M_UI_PLAY_MAP.X, j + M_UI_PLAY_MAP.Y);
			cout << "||";
		}
	}

	/* print next block ui */
	//for(int i=0; i<MAP_WIDTH)
}

void PrintoutProcessor::printPlayMap(MapData* pData, Block* pBlock){
	//cout << "printmap" << endl;
	short mapPoint;
	MAPPOS blockPosArray[4];

	for(int k=0; k<4; k++){
		blockPosArray[k] = pBlock->getPos(k);
	}

	for(int i=0; i<MAP_WIDTH; i++){
		for(int j=2; j<MAP_HEIGHT; j++){
			//upper 2 is hidden area
			gotoxy(i*2 + M_UI_PLAY_MAP.X + 2, j + M_UI_PLAY_MAP.Y - 1);

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
			case 8:
				cout << "¡à";
				break;
			default:
				cout << "??";
				break;
			}
		}
	}
}

void PrintoutProcessor::printNextBlock(Block* pNextBlock){
	MAPPOS blockPosArray[4];

	for(int k=0; k<4; k++){
		blockPosArray[k] = pNextBlock->getPos(k);
		blockPosArray[k].X -= 3;
	}

	for(int i=0; i<4; i++){
		for(int j=0; j<2; j++){
			gotoxy(i*2 + M_UI_NEXT_BLOCK.X, j +  M_UI_NEXT_BLOCK.Y);
			short mapPoint = 0;
			for(int k=0; k<4; k++){
				if(blockPosArray[k].X == i && blockPosArray[k].Y == j)
				{
					mapPoint = pNextBlock->getType();
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

void PrintoutProcessor::clearConsole(){
	gotoxy(0, 0);
	system("cls");
}

void PrintoutProcessor::gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
