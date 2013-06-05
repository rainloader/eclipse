//============================================================================
// Name        : tcp_ip_client.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <winsock2.h>


void processError(char* msg);

int main() {
	SOCKET hSocket;	//socket to connect server
	const int bufferSize = 1024;
	WSADATA wsaData;
	struct sockaddr_in server_addr;
	char bufferRcv[bufferSize+5];
	char bufferSnd[bufferSize+5];

	int strLen;

	const char* ip = "10.0.2.15";
	const short port = 4000;

	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		processError("[ERROR]WSA init");

	hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(hSocket == INVALID_SOCKET)
		processError("[ERROR]socket error");


	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.S_un.S_addr = inet_addr(ip);
	server_addr.sin_port = htons(port);

	if(connect(hSocket, (SOCKADDR*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR)
		processError("[ERROR]connect error");

	printf("Server Connected");

	scanf("%s", bufferSnd);

	send(hSocket, bufferSnd, sizeof(bufferSnd), 0);


	strLen = recv(hSocket, bufferRcv, sizeof(bufferRcv) -1, 0);
	if(strLen == -1)
		processError("[ERROR]recv error");

	bufferRcv[strLen] = 0;
	printf("receive : %s \n", bufferRcv);

	closesocket(hSocket);
	WSACleanup();

	return 0;
}


void processError(char* msg){
	printf("message : %s\n", msg);
	printf("%u", GetLastError());
	system("pause");
	exit(1);
}
