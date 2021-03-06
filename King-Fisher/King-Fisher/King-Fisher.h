#pragma once

#include "stdafx.h"
#include "Encryptor.h"
// TODO: reference additional custom headers your program requires here

#pragma once
#ifndef _FILEIO_
#define _FILEIO_
// required standard libary files are: iostream, string, fstream and cstdio

class FILEIO {
public:
	FILEIO() {
		std::string filename = "copytarget.txt";
		std::ofstream outfile(filename.c_str());

		wchar_t* fileLPCWSTR = L"copytarget.txt"; // To avoid incompatibility in GetFileAttributes()

		int attr = GetFileAttributes(fileLPCWSTR);
		if ((attr & FILE_ATTRIBUTE_HIDDEN) == 0) {
			SetFileAttributes(fileLPCWSTR, attr | FILE_ATTRIBUTE_HIDDEN);
		}
	};

	static void Fenter(std::string input) {
		std::cout << input << std::endl;
		input += '\n';
		const char * c = input.c_str();

		string s;
		string sTotal;

		ifstream in;
		in.open(input);

		while (!in.eof()) {
				getline(in, s);
				sTotal += s + "\n";
			}

			cout << sTotal;
		}

	};
};
#endif // !_FILEIO_