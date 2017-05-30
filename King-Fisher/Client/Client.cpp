//Client

#include "stdafx.h"

using namespace std;

WSAData wsaData;
struct addrinfo *result = NULL, *ptr = NULL, hints;
struct sockaddr_in Destination;
int LengthOfMessageFromServer;
int ClientSocket;


int main() {

	int MAXRCV = 512;
	char *Buffer;
	Buffer = (char*)malloc((MAXRCV + 1) * sizeof(char));

	int StartupResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (StartupResult != 0) {
		cout << ("WSAStartup failed with error %d\n", WSAGetLastError()) << endl;
		system("pause");
		return EXIT_FAILURE;
	};

	SOCKET ClientSocket;
	ClientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ClientSocket == SOCKET_ERROR || ClientSocket == INVALID_SOCKET) {
		cout << ("Socket failed to load: %d\n", WSAGetLastError()) << endl;
		system("pause");
		return EXIT_FAILURE;
	};

	string _Address;
	string StrPort;
	cout << "Enter address to connect to: ", cin >> _Address;
	cout << "Enter port number: ", cin >> StrPort;
	const char * Address = _Address.c_str();
	int Port = stoi(StrPort);
	cout << "Port: " << Port << "\nAddress: " << Address << endl;

	memset(&Destination, 0, sizeof(Destination));
	Destination.sin_family = AF_INET;
	Destination.sin_addr.s_addr = inet_addr(Address);
	Destination.sin_port = htons(Port);

	connect(ClientSocket, (struct sockaddr *)&Destination, sizeof(struct sockaddr));

	while (ClientSocket != INVALID_SOCKET) {
		LengthOfMessageFromServer = recv(ClientSocket, Buffer, MAXRCV, 0);
		printf("Received message: %s (%d Bytes)\n", Buffer, LengthOfMessageFromServer);
	};

	if (WSACleanup() == SOCKET_ERROR) {
		cout << ("WSACleanup failed, error: %d\n", WSAGetLastError()) << endl;
		system("pause");
		return EXIT_FAILURE;
	};

	return EXIT_SUCCESS;
};