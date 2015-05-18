#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "msg.h"


using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 5)
	{
		cout << "args is not correct!" << endl;
		return 0;
	}

	int connet_fd;

	char* serverIP = argv[1];
	int serverPort = atoi(argv[2]);
	char* clientIP = argv[3];
	int clientPort = atoi(argv[4]);
	char* clientID = argv[5];

	char strategyName[28] = "";
	if(argc >= 7)
		strcpy(strategyName, argv[6]);

	int socket_id = -1;
	if ((socket_id = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		cout << "create socket failed!" << endl;
		return 0;
	}

	int is_reuse_addr = 1;
	setsockopt(socket_id, SOL_SOCKET, SO_REUSEADDR,
			(const char*) &is_reuse_addr, sizeof(is_reuse_addr));

	struct sockaddr_in client_addr;
	memset(&client_addr, 0, sizeof(&client_addr));

	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(clientPort);
	client_addr.sin_addr.s_addr = inet_addr(clientIP);
	//server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(socket_id, (struct sockaddr *) &client_addr, sizeof(client_addr))
			< 0)
	{
		cout << "bind failed!\n" << endl;
		return 0;
	}

	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(&server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(serverPort);
	if (inet_pton(AF_INET, serverIP, &server_addr.sin_addr) <= 0)
	{
		cout << "inet_pton error for " << serverIP << endl;
		return 0;
	}
	while (connect(socket_id, (struct sockaddr*) &server_addr,
			sizeof(server_addr)) < 0){
                cout << clientIP <<" "<<clientPort<<" "<<serverIP <<" "<<serverPort<< endl;
		usleep(1000 * 1000);
        }

	char msg[100];
	sprintf(msg, "reg:%s %s \n", clientID, clientID);
	send(socket_id, msg, strlen(msg), 0);


	MsgProcessor mp(socket_id, strategyName);

	do
	{
		char buffer[1024] = { 0 };
		int re = recv(socket_id, buffer, 1024, 0);
		if (re > 0)
		{
			buffer[re] = 0;

			if(mp.ProcessMsg(buffer))
				break;
		}
	} while (1);

	close(socket_id);
	return 0;
}
