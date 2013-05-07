/*
 * main.cpp
 *
 *  Created on: 2013. 5. 7.
 *      Author: alligator410
 */

#include <iostream>
#include "TemplateFunction.cpp"

using namespace std;

int main()
{
	int ia = 3;
	int ib = 5;
	int iMaxVal = getMaxVal(ia, ib);
	cout << iMaxVal << endl;

	short sa = 4;
	short sb = 2;
	cout << getMaxVal(sa, sb) << endl;

	char ca = 'c';
	char cb = 'd';
	cout << getMaxVal(ca, cb) << endl;

	return 0;
}
