/*
 * CentralManager.cpp
 *
 *  Created on: 2013. 6. 3.
 *      Author: �÷������
 */

#include "CentralManager.h"

CentralManager::CentralManager()
: mpNetworkConnectManager (new NetworkConnectManager()),
  mpUIController(new UIController()){

}

CentralManager::~CentralManager() {
	delete mpNetworkConnectManager;
	delete mpUIController;
}

