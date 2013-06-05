/*
 * NetworkConnectManager.h
 *
 *  Created on: 2013. 6. 3.
 *      Author: ÇÃ·§Æû¿î¿µÆÀ
 */

#ifndef NETWORKCONNECTMANAGER_H_
#define NETWORKCONNECTMANAGER_H_

#include <vector>
#include "Client.h"

class NetworkConnectManager {
public:
	NetworkConnectManager();
	~NetworkConnectManager();

	//Run Server.
	void runServer();

	/* Stop Server. Aha. Server have it`s own console...Ui(whatever) to control server`s context. When it decided to run, it runs, and it decided to stop, it stops.
	 * Unlike offline games, even gamers stop game, server doesn`t stop. */
	void stopServer();

private:
	/* TODO: NCM requires player`s pool variable. Player`s pool? maybe we`d better to create client class(Not player in game). */
	std::vector<Client> mClientPool;
};

#endif /* NETWORKCONNECTMANAGER_H_ */
