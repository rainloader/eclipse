/*
 * CTManager.h
 *
 *  Created on: 2013. 4. 16.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef CTMANAGER_H_
#define CTMANAGER_H_

#include "InputHandler.h"

class CTManager {
public:
	CTManager();
	~CTManager();

	void start();
protected:
	InputHandler mInputHandler;


private:

};

#endif /* CTMANAGER_H_ */
