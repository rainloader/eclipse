/*
 * InputHandler.cpp
 *
 *  Created on: 2013. 4. 16.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "InputHandler.h"
#include <process.h>
#include <iostream>
#include <conio.h>
/**/#include <stdio.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

#define KEY_1P_LEFT			75	//left key
#define KEY_1P_RIGHT		77	//right key
#define KEY_1P_DOWN			80	//down key
#define KEY_1P_DROP			81	//pgdn key
#define KEY_1P_ROTATE_CW	72	//up key
#define KEY_1P_ROTATE_CCW	79	//end key


InputHandler::InputHandler(Notifiable* callee) : callee_(callee) {
	mHThread = 0;
	keyStat = 0;
}

InputHandler::~InputHandler() {
	// TODO Auto-generated destructor stub
}

void InputHandler::startThread() {
	mHThread = (HANDLE) _beginthreadex(NULL, 0, runThread, (LPVOID)this, 0, NULL);
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

UINT WINAPI InputHandler::runThread(LPVOID p){
	InputHandler* pInputHandler = (InputHandler*) p;
	pInputHandler->run();
	return 0;
}

void InputHandler::run(){
	int keyState = 0;
	while(keyState != -1){
		if(kbhit()){
			char ch = getch();
			//if(ch == 0 || ch==0x00)
			//{
				//ch = getch();
				switch(ch){
				case KEY_1P_LEFT:
					passInput(NOTIFY_INPUT_1P_LEFT);
					break;
				case KEY_1P_RIGHT:
					passInput(NOTIFY_INPUT_1P_RIGHT);
					break;
				case KEY_1P_DOWN:
					passInput(NOTIFY_INPUT_1P_DOWN);
					break;
				case KEY_1P_DROP:
					passInput(NOTIFY_INPUT_1P_DROP);
					break;
				case KEY_1P_ROTATE_CW:
					passInput(NOTIFY_INPUT_1P_ROTATE_CW);
					break;
				case KEY_1P_ROTATE_CCW:
					passInput(NOTIFY_INPUT_1P_ROTATE_CCW);
					break;
				default:
					break;
				//}
			}
		}
	}
}

void InputHandler::passInput(int callerInputType){
	callee_->notify(callerInputType);
}


