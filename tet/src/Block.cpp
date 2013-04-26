/*
 * Block.cpp
 *
 *  Created on: 2013. 4. 25.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#include "Block.h"

Block::Block() {
	// TODO Auto-generated constructor stub
	for(int i=0; i<4; i++){
		mBlockPosArray[i].X = 0;
		mBlockPosArray[i].Y = 0;
	}
	mType = 1;
	mRotatingStatus = 1;
}

Block::~Block() {
	// TODO Auto-generated destructor stub
}

int Block::setBlockType(short blockType){
	/*set block type*/
	switch(blockType){
	case TYPE_I_BLOCK:
		mType = TYPE_I_BLOCK;
		mBlockPosArray[0].X = 4;
		mBlockPosArray[0].Y = 1;
		mBlockPosArray[1].X = 3;
		mBlockPosArray[1].Y = 1;
		mBlockPosArray[2].X = 5;
		mBlockPosArray[2].Y = 1;
		mBlockPosArray[3].X = 6;
		mBlockPosArray[3].Y = 1;
		break;
	case TYPE_J_BLOCK:
		mType = TYPE_J_BLOCK;
		mBlockPosArray[0].X = 4;
		mBlockPosArray[0].Y = 1;
		mBlockPosArray[1].X = 3;
		mBlockPosArray[1].Y = 0;
		mBlockPosArray[2].X = 3;
		mBlockPosArray[2].Y = 1;
		mBlockPosArray[3].X = 5;
		mBlockPosArray[3].Y = 1;
		break;
	case TYPE_L_BLOCK:
		mType = TYPE_L_BLOCK;
		mBlockPosArray[0].X = 4;
		mBlockPosArray[0].Y = 1;
		mBlockPosArray[1].X = 3;
		mBlockPosArray[1].Y = 1;
		mBlockPosArray[2].X = 5;
		mBlockPosArray[2].Y = 0;
		mBlockPosArray[3].X = 5;
		mBlockPosArray[3].Y = 1;
		break;
	case TYPE_O_BLOCK:
		mType = TYPE_O_BLOCK;
		mBlockPosArray[0].X = 4;
		mBlockPosArray[0].Y = 1;
		mBlockPosArray[1].X = 4;
		mBlockPosArray[1].Y = 0;
		mBlockPosArray[2].X = 5;
		mBlockPosArray[2].Y = 0;
		mBlockPosArray[3].X = 5;
		mBlockPosArray[3].Y = 1;
		break;
	case TYPE_S_BLOCK:
		mType = TYPE_S_BLOCK;
		mBlockPosArray[0].X = 4;
		mBlockPosArray[0].Y = 1;
		mBlockPosArray[1].X = 3;
		mBlockPosArray[1].Y = 1;
		mBlockPosArray[2].X = 4;
		mBlockPosArray[2].Y = 0;
		mBlockPosArray[3].X = 5;
		mBlockPosArray[3].Y = 0;
		break;
	case TYPE_T_BLOCK:
		mType = TYPE_T_BLOCK;
		mBlockPosArray[0].X = 4;
		mBlockPosArray[0].Y = 1;
		mBlockPosArray[1].X = 3;
		mBlockPosArray[1].Y = 1;
		mBlockPosArray[2].X = 4;
		mBlockPosArray[2].Y = 0;
		mBlockPosArray[3].X = 5;
		mBlockPosArray[3].Y = 1;
		break;
	case TYPE_Z_BLOCK:
		mType = TYPE_Z_BLOCK;
		mBlockPosArray[0].X = 4;
		mBlockPosArray[0].Y = 1;
		mBlockPosArray[1].X = 3;
		mBlockPosArray[1].Y = 1;
		mBlockPosArray[2].X = 4;
		mBlockPosArray[2].Y = 0;
		mBlockPosArray[3].X = 5;
		mBlockPosArray[3].Y = 0;
		break;
		/* if there`s invalid block type, return error state */
	default:
		return 1;
		break;
	}
	/* initialize rotating status */
	mRotatingStatus = ROTATING_STATUS_12;
	return 0;
}

void Block::rotate(short rotatingDirection){

}
