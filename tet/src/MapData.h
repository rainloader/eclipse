/*
 * GameInfo.h
 *
 *  Created on: 2013. 4. 23.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef GAMEINFO_H_
#define GAMEINFO_H_


#define MAP_WIDTH 10
#define MAP_HEIGHT 22 //Hidden 2

class MapData {
public:
	MapData();
	MapData(const MapData& mapData);
	~MapData();

	void initialize();
	short getMapPoint(int X, int Y);
	void setMapPoint(int X, int Y, short pointValue);
protected:

	/* map code
	 * 0 - empty
	 * 1 - I block
	 * 2 - J block
	 * 3 - L block
	 * 4 - O block
	 * 5 - S block
	 * 6 - T block
	 * 7 - Z block
	 * 8 - clearLine effect
	 * */
	short map[MAP_WIDTH][MAP_HEIGHT];
};

#endif /* GAMEINFO_H_ */
