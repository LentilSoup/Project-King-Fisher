#pragma once
#include "stdafx.h"

#ifndef _KGFR_ENCRYPTION_
#define _KGFR_ENCRYPTION_

class FUISMaths {
public:
	long int ChkCoprime(long int seconds, long int address) {
		bool Coprime = (address<seconds) ? ChkCoprime(seconds, address) : !(address%seconds) ? (seconds == 1) : ChkCoprime(seconds, address%seconds);
		if (Coprime != true) {
			seconds++;
			ChkCoprime(seconds,address);
		}
		if (Coprime == false) {
			return seconds, address;
		};
	};
	int factorial(int x, int result = 1) {
		if (x == 1) return result; else return factorial(x - 1, x * result);
	}
protected:





};



class FUISEncryption: public FUISMaths {
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