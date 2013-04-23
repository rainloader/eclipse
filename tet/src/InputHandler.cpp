/*
 * InputHandler.cpp
 *
 *  Created on: 2013. 4. 16.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "InputHandler.h"
#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

InputHandler::InputHandler() {
	// TODO Auto-generated constructor stub
	keyStat = 0;
}

InputHandler::~InputHandler() {
	// TODO Auto-generated destructor stub
}

UINT WINAPI InputHandler::receiveInputT(LPVOID p){
	int keyState = 0;

	while(keyState != -1){
		if(kbhit()){
			char ch = getch();
			/**/cout << ch << endl;
		}
	}
/*
	int keycode=0;


	if(GetAsyncKeyState(WM_KEYDOWN)){
		cout << "!!!!!!!!!" << endl;
	}

	while(keycode!=-1)
	{
	keycode=0;



	if(GetAsyncKeyState(VK_UP))
	keycode=1;


	if(GetAsyncKeyState(VK_LEFT))
	{
	if(keycode==1)
	keycode=3;
	else
	keycode=2;
	}

	if(GetAsyncKeyState(VK_LEFT))
	{
	if(keycode==1)
	keycode=3;
	else
	keycode=2;
	}


	if(GetAsyncKeyState(VK_ESCAPE))
	keycode=-1;


	cout<< keycode<< endl;
	system("cls");
	}*/

	return 0;
}

char InputHandler::receiveInput(){
	char ch = 0;
	while(ch == 0){
		if(kbhit()){
			ch = getch();
			return ch;
		}
	}
	return 0;
}

void InputHandler::setKeyStat(char key){
	keyStat = key;
}
