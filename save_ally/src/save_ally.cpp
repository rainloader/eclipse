//============================================================================
// Name        : save_ally.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int save_ally(int iNumOfMember);
bool is_appropriate_interval(int iNumOfMember, int iInterval);

int main() {










	for(int i=1; i<=13; i++){
		cout << i << " " << save_ally(i) << endl;
	}
	//cout << save_ally(3) << endl;






}










int save_ally(int iNumOfMember){

	// test from interval 1
	for(int iInterval=iNumOfMember+1; /*iInterval<=(iNumOfMember*2)*/; iInterval++){
		if(is_appropriate_interval(iNumOfMember, iInterval)){
			return iInterval;
		}
	}

	// if there`s no answer
	return -1;
}

bool is_appropriate_interval(int iNumOfMember, int iInterval){
	char* pcLineUpArray = new char[iNumOfMember*2];
	for(int i=0; i<iNumOfMember; i++){
		pcLineUpArray[i] = 'a';
		pcLineUpArray[iNumOfMember+i] = 'e';
	}

	int iDisplace = 0;
	int i = -1;
	int iCountKillingEnemy = 0;
	while(iCountKillingEnemy != iNumOfMember){
		iDisplace++;
		//skip dead person. only admit alive person.
		do{
			i = (i+1)%(iNumOfMember*2);
		}
		while(pcLineUpArray[i] == 'd');
		//when moved interval
		if(iDisplace == iInterval){
			//if target is ally, it is wrong interval.
			 if(pcLineUpArray[i] == 'a'){
				delete [] pcLineUpArray;
				return false;
			 }
			 else{
				//else, kill enemy and count killing enemy.
				pcLineUpArray[i] = 'd';
				iCountKillingEnemy++;
				iDisplace = 0;
			 }
		}
	}
	delete [] pcLineUpArray;
	return true;
}






