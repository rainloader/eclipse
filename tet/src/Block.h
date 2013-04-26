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

#define MOVING_DIRECTION_LEFT 1
#define MOVING_DIRECTION_RIGHT 2
#define MOVING_DIRECTION_DOWN 3
#define MOVING_DIRECTION_UP 4

typedef struct _MAPPOS{
	short X;
	short Y;
} MAPPOS, *PMAPPOS;

class Block {
public:
	Block();
	Block(const Block& block);
	~Block();
	int setType(short blockType);
	short getType();
	MAPPOS getPos(int index);

	int move(short movingDirection);
	int rotate(short rotatingDirection);

	Block getMovedBlock(short movingDirection);
	Block getRotatedBlock(short rotatingDirection);



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
	MAPPOS mBlockPosArray[4];
};

#endif /* BLOCK_H_ */
