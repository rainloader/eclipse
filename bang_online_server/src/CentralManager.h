/*
 * CentralManager.h
 *
 *  Created on: 2013. 6. 3.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef CENTRALMANAGER_H_
#define CENTRALMANAGER_H_

#include "ui/UIController.h"
#include "network/NetworkConnectManager.h"

enum SERVER_STATE{
	INIT,
	RUN,
	STOP,
	SHUTDOWN
};

class CentralManager {
public:
	CentralManager();
	~CentralManager();

	void process();

private:
	NetworkConnectManager* mpNetworkConnectManager;
	UIController* mpUIController;
	SERVER_STATE mServerState;
};

#endif /* CENTRALMANAGER_H_ */
