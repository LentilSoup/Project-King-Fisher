#pragma once
#include "stdafx.h"

#ifndef _KGFR_ENCRYPTION_
#define _KGFR_ENCRYPTION_

class FUISEncryption {
public:
	void encrypt(std::string memLoc) {

		time_t seconds;
		seconds = time(NULL);

		std::string binarytime = std::bitset<64>(seconds).to_string(); //to binary
		


		std::string binaryaddress = std::bitset<64>(seconds).to_string(); //to binary
	
	
	
	};

	void decrypt() {






	};
};


#endif //__!_KGFR_ENCRIPTION_