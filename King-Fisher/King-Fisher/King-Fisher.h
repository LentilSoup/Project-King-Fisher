#pragma once

#include "stdafx.h"
// TODO: reference additional custom headers your program requires here

#pragma once
#ifndef _FILEIO_
#define _FILEIO_
// required standard libary files are: iostream, string, fstream and cstdio

using namespace std;

class FILEIO {
public:
	FILEIO() {
		string filename = "copytarget.KgFr";
		ofstream outfile(filename.c_str());

		wchar_t* fileLPCWSTR = L"copytarget.KgFr"; // To avoid incompatibility in GetFileAttributes()

		int attr = GetFileAttributes(fileLPCWSTR);
		if ((attr & FILE_ATTRIBUTE_HIDDEN) == 0) {
			SetFileAttributes(fileLPCWSTR, attr | FILE_ATTRIBUTE_HIDDEN);
		}
	};

	static void Fenter(string input) {
		cout << input << endl;
		input += '\n';
		const char * c = input.c_str();

		string s;
		string sTotal;

		ifstream in;
		in.open(input);

		while (!in.eof()) {
				getline(in, s);
				sTotal += s + "\n";
		};
		cout << sTotal;
	};
};

#endif // !_FILEIO_