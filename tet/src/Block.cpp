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
}
Block::Block(const Block& block) {
	for(int i=0; i<4; i++)
		mBlockPosArray[i] = block.mBlockPosArray[i];
	mType = block.mType;
}

Block::~Block() {

}

int Block::setType(short blockType){
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
	return 0;
}

short Block::getType(){
	return mType;
}

MAPPOS Block::getPos(int index){
	return mBlockPosArray[index];
}

int Block::move(short movingDirection){
	MAPPOS displacement;
	switch(movingDirection){
	case MOVING_DIRECTION_LEFT:
		displacement.X = -1;
		displacement.Y = 0;
		break;
	case MOVING_DIRECTION_RIGHT:
		displacement.X = 1;
		displacement.Y = 0;
		break;
	case MOVING_DIRECTION_DOWN:
		displacement.X = 0;
		displacement.Y = 1;
		break;
	case MOVING_DIRECTION_UP:
		displacement.X = 0;
		displacement.Y = -1;
		break;
	default:
		return 1;
		break;
	}

	for(int i=0; i<3; i++){
		mBlockPosArray[i].X += displacement.X;
		mBlockPosArray[i].Y += displacement.Y;
	}
	return 0;
}

int Block::rotate(short rotatingDirection){
	//MAPPOS newPos;
	MAPPOS relativePos;

	switch(rotatingDirection){
	case ROTATING_DIRECTION_CLOCKWISE:
		for(int i=1; i<3; i++){
			relativePos.X = mBlockPosArray[i].X - mBlockPosArray[0].X;
			relativePos.Y = mBlockPosArray[i].Y - mBlockPosArray[0].Y;
			mBlockPosArray[i].X = mBlockPosArray[0].X + relativePos.Y * -1;
			mBlockPosArray[i].Y = mBlockPosArray[0].Y + relativePos.X * 1;
		}
		break;
	case ROTATING_DIRECTION_COUNTERCLOCK:
		for(int i=1; i<3; i++){
			relativePos.X = mBlockPosArray[i].X - mBlockPosArray[0].X;
			relativePos.Y = mBlockPosArray[i].Y - mBlockPosArray[0].Y;
			mBlockPosArray[i].X = mBlockPosArray[0].X + relativePos.Y * 1;
			mBlockPosArray[i].Y = mBlockPosArray[0].Y + relativePos.X * -1;
		}
		break;
	default:
		return 1;
		break;
	}
	return 0;
}

Block Block::getMovedBlock(short movingDirection){
	Block movedBlock = *this;
	movedBlock.move(movingDirection);
	return movedBlock;
}

Block Block::getRotatedBlock(short rotatingDirection){
	Block rotatedBlock = *this;
	rotatedBlock.rotate(rotatingDirection);
	return rotatedBlock;
}
