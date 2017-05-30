//Server

#include "stdafx.h"
#define DEFAULT_BUFLEN 512

using namespace std;

WSAData wsaData;
struct addrinfo *result = NULL, *ptr = NULL, hints;
struct sockaddr_in Destination;
int SocketSize = sizeof(sockaddr_in);
string Message = "Connection received.";


int main() {
	int StartupResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (StartupResult != 0) {
		cout << ("WSAStartup failed with error %d\n", WSAGetLastError()) << endl;
		
		return EXIT_FAILURE;
	};

	SOCKET ServerSocket;
	ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ServerSocket == SOCKET_ERROR || ServerSocket == INVALID_SOCKET) {
		cout << ("Socket failed to load: %d\n", WSAGetLastError()) << endl;
		
		return EXIT_FAILURE;
	};

	string StrPort;
	cout << "Enter Port: ", cin >> StrPort;
	int Port = stoi(StrPort);

	SOCKADDR_IN Server;

	Server.sin_port = htons(Port);
	Server.sin_family = AF_INET;
	Server.sin_addr.s_addr = INADDR_ANY;

	if (bind(ServerSocket, (SOCKADDR *)(&Server), sizeof(Server)) == SOCKET_ERROR) {
		cout << ("Socket bind failed: %d\n", SOCKET_ERROR) << endl;
		
		return EXIT_FAILURE;
	};

	listen(ServerSocket, 10);
	SOCKET ConnectionSocket = accept(ServerSocket, (struct sockaddr *)&Destination, &SocketSize);

	do {
		cout << ("Incoming connection from: %s", inet_ntoa(Destination.sin_addr)) << endl;
		cin >> Message;
		send(ConnectionSocket, Message.c_str(), strlen(Message.c_str()), 0);

	} while (ServerSocket != SOCKET_ERROR);

	if (WSACleanup() == SOCKET_ERROR) {
		cout << ("WSACleanup failed, error: %d\n", WSAGetLastError()) << endl;
		
		return EXIT_FAILURE;
	};
	closesocket(ConnectionSocket);
	closesocket(ServerSocket);

	return EXIT_SUCCESS;
};
