/*
 * PrintoutProcessor.cpp
 *
 *  Created on: 2013. 4. 23.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "PrintoutProcessor.h"

#include <iostream>

using namespace std;

PrintoutProcessor::PrintoutProcessor() {
	// TODO Auto-generated constructor stub
	//M_UI_PLAY_MAP = {5, 5};
}

PrintoutProcessor::~PrintoutProcessor() {
	// TODO Auto-generated destructor stub
}

void PrintoutProcessor::printPlayMap(const Data* pData){
	cout << "printmap" << endl;
	for(int i=0; i<MAP_HEIGHT; i++){
		for(int j=0; j<MAP_WIDTH; j++){
			//short mapPoint = pData->getMapPoint(i, j);
			gotoxy(i, j);
			cout << "¡á";
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
