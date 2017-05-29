#pragma once
#include "stdafx.h"

#ifndef _KGFR_ENCRYPTION_
#define _KGFR_ENCRYPTION_

class FUISMaths {
public:
	unsigned int gcd(unsigned int a, unsigned int b)
	{
		unsigned int x;
		while (b)
		{
			x = a % b;
			a = b;
			b = x;
		}
		return a;
	}
	int phi(unsigned int n)
	{
		unsigned int result = 1;
		for (int i = 2; i < n; i++)
			if (gcd(i, n) == 1)
				result++;
		return result;
	}


};



class FUISEncryption: public FUISMaths {
public:
	void encrypt(std::string memLoc) {

		time_t seconds;									//FUIS Encryption start
		seconds = time(NULL);


		while (memLoc[i]) {											  //changes memory address to binary 
			switch (memLoc[i]) {
			case '0': binaryaddress += "0000"; break;
			case '1': binaryaddress += "0001"; break;
			case '2': binaryaddress += "0010"; break;
			case '3': binaryaddress += "0011"; break;
			case '4': binaryaddress += "0100"; break;
			case '5': binaryaddress += "0101"; break;
			case '6': binaryaddress += "0110"; break;
			case '7': binaryaddress += "0111"; break;
			case '8': binaryaddress += "1000"; break;
			case '9': binaryaddress += "1001"; break;
			case 'A': binaryaddress += "1010"; break;
			case 'B': binaryaddress += "1011"; break;
			case 'C': binaryaddress += "1100"; break;
			case 'D': binaryaddress += "1101"; break;
			case 'E': binaryaddress += "1110"; break;
			case 'F': binaryaddress += "1111"; break;
			case 'a': binaryaddress += "1010"; break;
			case 'b': binaryaddress += "1011"; break;
			case 'c': binaryaddress += "1100"; break;
			case 'd': binaryaddress += "1101"; break;
			case 'e': binaryaddress += "1110"; break;
			case 'f': binaryaddress += "1111"; break;
			default:  std::cout << "nInvalid hexadecimal digit " << memLoc[i];
			}
			i++;
		}															  //end of hex to binary
		
		std::string binarytime = std::bitset<64>(seconds).to_string(); //decimal to binary


		binarytime += "1";
		binaryaddress += "0";
		
		unsigned long decimaltime = std::bitset<64>(binarytime).to_ulong();    //change from binary into decimal
		unsigned long decimaladdress = std::bitset<64>(binaryaddress).to_ulong(); //change from binary into deciaml
		
	
		GCDR:
			if (gcd(decimaladdress, decimaltime) != 1) {
				decimaladdress++;
				goto GCDR;
			}
			else {
				std::clog << "Coprimes" << std::endl;
			}

	};																	//FUIS encryption ends

	void decrypt() {






	};
protected:
	long int i = 0;
	std::string binaryaddress = "";
};


#endif //__!_KGFR_ENCRIPTION_