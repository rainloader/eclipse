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

void PrintoutProcessor::printPlayMap(MapData* pData){
	//cout << "printmap" << endl;
	for(int i=0; i<MAP_WIDTH; i++){
		for(int j=2; j<MAP_HEIGHT; j++){
			//upper 2 is hidden area
			gotoxy(i*2, j-2);
			short mapPoint = pData->getMapPoint(i, j);
			if(mapPoint == 0)
				cout << "  ";
			else
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
