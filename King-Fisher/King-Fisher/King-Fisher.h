#pragma once

#include "stdafx.h"
// TODO: reference additional custom headers your program requires here

#pragma once
#ifndef _FILEIO_
#define _FILEIO_
// required standard libary files are: iostream, string, fstream and cstdio

class FILEIO {
public:
	FILEIO() {
		std::string filename = "copytarget.KgFr";
		std::ofstream outfile(filename.c_str());
	};

	static void Fenter(std::string input) {
		std::cout << input << std::endl;
		input += '\n';
		const char * c = input.c_str();

		wchar_t* fileLPCWSTR = L"copytarget.KgFr"; // To avoid incompatibility
													  // in GetFileAttributes()
		int attr = GetFileAttributes(fileLPCWSTR);
		if ((attr & FILE_ATTRIBUTE_HIDDEN) == 0) {
			SetFileAttributes(fileLPCWSTR, attr | FILE_ATTRIBUTE_HIDDEN);
		}


		FILE * path;
		path = fopen("Errlog.txt", "a");
		if (path != NULL) {
			fputs(c, path);
			fclose(path);
		};
	};
};
#endif // !_FILEIO_