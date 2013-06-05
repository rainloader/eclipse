/*
 * tcp_ip_server.cpp
 *
 *  Created on: 2013. 6. 5.
 *      Author: alligator410
 */

#include <stdio.h>
#include <winsock2.h>

void processError(char* msg);


int main(){
	WSADATA wsaData;
	const int BUFFER_SIZE = 1024;
	SOCKET hServerSocket;
	SOCKET hClientSocket;
	SOCKADDR_IN serverAddr;
	SOCKADDR_IN clientAddr;

	char bufferRcv[BUFFER_SIZE+5];
	char bufferSnd[BUFFER_SIZE+5];

	int szClientAddr;

	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		processError("[ERROR]WSA init");

	hServerSocket = socket(PF_INET, SOCK_STREAM, 0);
	if(hServerSocket == INVALID_SOCKET)
		processError("[ERROR]socket error");

	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(4000);

	if(bind(hServerSocket, (SOCKADDR*) &serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		processError("[ERROR]bind error");

	if(listen(hServerSocket, 5) == SOCKET_ERROR)
		processError("[ERROR]listen error");

	szClientAddr = sizeof(clientAddr);

	hClientSocket = accept(hServerSocket, (SOCKADDR*)&clientAddr, &szClientAddr);
	if(hClientSocket == INVALID_SOCKET)
		processError("[ERROR]accept error");

	recv(hClientSocket, bufferRcv, sizeof(bufferRcv), 0);
	printf("Receive : %s\n", bufferRcv);
	sprintf(bufferSnd, "%d : %s", strlen(bufferRcv), bufferRcv);

	send(hClientSocket, bufferSnd, sizeof(bufferSnd), 0);

	closesocket(hClientSocket);

	WSACleanup();
	return 0;
}



void processError(char* msg){
	printf("message : %s\n", msg);
	printf("%u", GetLastError());
	system("pause");
	exit(1);
}
