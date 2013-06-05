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

class CentralManager {
public:
	CentralManager();
	~CentralManager();

private:
	NetworkConnectManager* mpNetworkConnectManager;
	UIController* mpUIController;

};

#endif /* CENTRALMANAGER_H_ */
