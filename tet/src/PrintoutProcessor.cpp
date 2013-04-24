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

void PrintoutProcessor::printPlayMap(Data* pData){
	//cout << "printmap" << endl;
	for(int i=0; i<MAP_WIDTH; i++){
		for(int j=0; j<MAP_HEIGHT; j++){
			gotoxy(i*2, j);
			short mapPoint = pData->getMapPoint(i, j);
			//usleep(5000);
			if(mapPoint == 0)
				cout << "  ";
			else
				cout << "¡á";
			//wchar_t block = '3';//0x25A0;
			//wcout << block;

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
