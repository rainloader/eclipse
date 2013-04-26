/*
 * Block.h
 *
 *  Created on: 2013. 4. 25.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#define ROTATING_DIRECTION_CLOCKWISE 1
#define ROTATING_DIRECTION_COUNTERCLOCK 2

#define TYPE_I_BLOCK 1
#define TYPE_J_BLOCK 2
#define TYPE_L_BLOCK 3
#define TYPE_O_BLOCK 4
#define TYPE_S_BLOCK 5
#define TYPE_T_BLOCK 6
#define TYPE_Z_BLOCK 7

#define ROTATING_STATUS_12 1
#define ROTATING_STATUS_3 2
#define ROTATING_STATUS_6 3
#define ROTATING_STATUS_9 4

typedef struct _MAPPOS{
	short X;
	short Y;
} MAPPOS, *PMAPPOS;

class Block {
public:
	Block();
	~Block();
	void rotate(short rotatingDirection);
	int setBlockType(short blockType);
	//COORD[] getBlockPosArray();

protected:
	/* block code
	 * 0 - empty
	 * 1 - I block
	 * 2 - J block
	 * 3 - L block
	 * 4 - O block
	 * 5 - S block
	 * 6 - T block
	 * 7 - Z block
	 * */
	short mType;
	short mRotatingStatus;
	MAPPOS mBlockPosArray[4];
};

#endif /* BLOCK_H_ */
