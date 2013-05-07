/*
 * PrintoutProcessor.cpp
 *
 *  Created on: 2013. 4. 23.
 *      Author: ╟├╖з╞√┐ю┐╡╞└
 */

#include "PrintoutProcessor.h"

#include <iostream>

#include <stdio.h>

using namespace std;

PrintoutProcessor::PrintoutProcessor() {
	// TODO Auto-generated constructor stub
	M_UI_PLAY_MAP.X = 2;
	M_UI_PLAY_MAP.Y = 1;

	M_UI_NEXT_BLOCK.X = 30;
	M_UI_NEXT_BLOCK.Y = 3;

	M_UI_PLAY_DATA.X = 30;
	M_UI_PLAY_DATA.Y = 15;
}

PrintoutProcessor::~PrintoutProcessor() {
	// TODO Auto-generated destructor stub
}

void PrintoutProcessor::printTitle(){
	cout << "TITLE" << endl;
	cout << "Press Any Key" << endl;
}

void PrintoutProcessor::printMenu(){
	cout << "MENU" << endl;
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
				setColor(0b1011, 0);//cyan
				cout << "бс";
				break;
			case 2:
				setColor(0b1001, 0);//blue
				cout << "бс";
				break;
			case 3:
				setColor(0b0110, 0);//orange->white
				cout << "бс";
				break;
			case 4:
				setColor(0b1110, 0);//yellow
				cout << "бс";
				break;
			case 5:
				setColor(0b1010, 0);//green
				cout << "бс";
				break;
			case 6:
				setColor(0b1101, 0);//purple
				cout << "бс";
				break;
			case 7:
				setColor(0b1100, 0);//red
				cout << "бс";
				break;
			case 8:
				setColor(0b0111, 0);
				cout << "в▌";
				break;
			default:
				cout << "??";
				break;
			}
		}
	}
	setColor(0b0111, 0);
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
				setColor(0b1011, 0);//cyan
				cout << "бс";
				break;
			case 2:
				setColor(0b1001, 0);//blue
				cout << "бс";
				break;
			case 3:
				setColor(0b0110, 0);//orange->white
				cout << "бс";
				break;
			case 4:
				setColor(0b1110, 0);//yellow
				cout << "бс";
				break;
			case 5:
				setColor(0b1010, 0);//green
				cout << "бс";
				break;
			case 6:
				setColor(0b1101, 0);//purple
				cout << "бс";
				break;
			case 7:
				setColor(0b1100, 0);//red
				cout << "бс";
				break;
			default:
				cout << "??";
				break;
			}
		}
	}
	setColor(0b0111, 0);
}

void PrintoutProcessor::printPlayData(int score, int line, int level){
	setColor(0b0111, 0);
	gotoxy(M_UI_PLAY_DATA.X+4, M_UI_PLAY_DATA.Y+2);
	cout << score;
	gotoxy(M_UI_PLAY_DATA.X+4, M_UI_PLAY_DATA.Y+4);
	cout << line;
	gotoxy(M_UI_PLAY_DATA.X+4, M_UI_PLAY_DATA.Y+6);
	cout << level;
}

void PrintoutProcessor::clearConsole(){
	setColor(0b0111, 0);
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

void PrintoutProcessor::setColor(int color, int bgcolor)

{

    color &= 0xf;

    bgcolor &= 0xf;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);

}

inline int PrintoutProcessor::_drgb ( bool d, bool r, bool g, bool b)
 {
     return (d << 3) + (r << 2) + (g << 1) + (b << 0);
 }



