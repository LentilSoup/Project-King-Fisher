#pragma once

#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib, "Ws2_32.lib")

int main() {

	WSAData wsa;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsa) != 0) {
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}

	return 0;
}
