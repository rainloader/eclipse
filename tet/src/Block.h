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


class Block {
public:
	Block();
	~Block();
	void rotate(int rotatingDirection);

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
	int mType;
	int mRotatingStatus;
};

#endif /* BLOCK_H_ */
