/*
 * InputHandler.cpp
 *
 *  Created on: 2013. 4. 16.
 *      Author: �÷������
 */

#include "InputHandler.h"
#include <windows.h>
#include <iostream>

using namespace std;

InputHandler::InputHandler() {
	// TODO Auto-generated constructor stub

}

InputHandler::~InputHandler() {
	// TODO Auto-generated destructor stub
}

UINT WINAPI InputHandler::receiveInput(LPVOID p){
	int keycode=0;


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
	}

	return 0;

}
