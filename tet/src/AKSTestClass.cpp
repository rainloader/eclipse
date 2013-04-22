/*
 * AKSTestClass.cpp
 *
 *  Created on: 2013. 4. 22.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "AKSTestClass.h"
#include <iostream>
#include <windows.h>

using namespace std;


AKSTestClass::AKSTestClass() {
	// TODO Auto-generated constructor stub

}

AKSTestClass::~AKSTestClass() {
	// TODO Auto-generated destructor stub
}

void AKSTestClass::test(){
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


	if(GetAsyncKeyState(VK_ESCAPE))
	keycode=-1;


	cout<< keycode<< endl;
	system("cls");
	}

}
