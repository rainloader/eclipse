/*
 * GameInfo.h
 *
 *  Created on: 2013. 4. 23.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef GAMEINFO_H_
#define GAMEINFO_H_

#define MAP_HEIGHT 20
#define MAP_WIDTH 10

class Data {
public:
	Data();
	~Data();

	void initialize();
	short getMapPoint(int i, int j);
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
	 * */
	short map[MAP_HEIGHT][MAP_WIDTH];

	int score;
	int line;
	int level;
};

#endif /* GAMEINFO_H_ */
