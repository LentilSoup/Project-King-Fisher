#include <Connection.h>
#include <iostream>

using namespace std;


int main() {

	int ServerPort = 845;
	SOCKADDR_IN ServerAddress;
	int AddressLength = sizeof(ServerAddress);
	ServerAddress.sin_port = htons(ServerPort);
	ServerAddress.sin_family = AF_INET;

	SOCKET Server = socket(AF_INET, SOCK_STREAM, NULL);
	bind(Server, (SOCKADDR*)&ServerAddress, AddressLength);
	listen(Server, SOMAXCONN);

	SOCKET NewConnection;
	NewConnection = accept(Server, (SOCKADDR*)&ServerAddress, &AddressLength);
	if (NewConnection == 0) {
		cout << "Failed to accept the client's connection." << endl;
	}
	else {
		cout << "Client Connected" << endl;
		char ConnectMessage[256] = "Connected.";
		send(NewConnection, ConnectMessage, sizeof(ConnectMessage), NULL);
	}

	system("pause");

	return 0;
}