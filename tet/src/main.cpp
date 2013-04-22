/*
 * main.cpp
 *
 *  Created on: 2013. 4. 16.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */
/*
#include "AKSTestClass.h"
#include "ThreadTestClass.h"
*/
#include "CTManager.h"
#include <windows.h>

using namespace std;

int main()
{
/*	AKSTestClass testClass;
	testClass.test();*/
/*	ThreadTestClass ttc;

	ttc.start();*/
	CTManager ctm;

	ctm.start();

	return 0;
}
