/*
 * GameInfo.cpp
 *
 *  Created on: 2013. 4. 23.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "MapData.h"

MapData::MapData() {
	initialize();
}

MapData::MapData(const MapData& mapData){
	for(int i=0; i<MAP_HEIGHT; i++){
		for(int j=0; j<MAP_WIDTH; j++){
			map[i][j] = mapData.map[i][j];
		}
	}

}

MapData::~MapData() {
	// TODO Auto-generated destructor stub
}

void MapData::initialize() {
	for(int i=0; i<MAP_HEIGHT; i++){
		for(int j=0; j<MAP_WIDTH; j++){
			map[i][j] = 0;
		}
	}
}

short MapData::getMapPoint(int X, int Y){
	return map[X][Y];
}

void MapData::setMapPoint(int X, int Y, short pointValue){
	map[X][Y] = pointValue;
}
