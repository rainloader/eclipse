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
protected:
	char map[MAP_HEIGHT][MAP_WIDTH];
	int score;
	int line;
	int level;
};

#endif /* GAMEINFO_H_ */
