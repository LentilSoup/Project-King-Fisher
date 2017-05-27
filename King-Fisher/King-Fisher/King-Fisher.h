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
		std::string filename = "Errlog.txt";
		std::ofstream outfile(filename.c_str());
	};

	static void Fenter(std::string input) {
		std::cout << input << std::endl;
		input += '\n';
		const char * c = input.c_str();

		FILE * path;
		path = fopen("Errlog.txt", "a");
		if (path != NULL) {
			fputs(c, path);
			fclose(path);
		};
	};
};
#endif // !_FILEIO_