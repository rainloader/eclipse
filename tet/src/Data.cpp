/*
 * GameInfo.cpp
 *
 *  Created on: 2013. 4. 23.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "Data.h"

Data::Data() {
	initialize();
}

Data::~Data() {
	// TODO Auto-generated destructor stub
}

void Data::initialize() {
	score = 0;
	line = 0;
	level = 0;

	for(int i=0; i<MAP_HEIGHT; i++){
		for(int j=0; j<MAP_WIDTH; j++){
			map[i][j] = 0;
		}
	}
}
