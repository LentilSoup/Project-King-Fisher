#pragma once
#include "stdafx.h"


#ifndef _KGFR_ENCRYPTION_
#define _KGFR_ENCRYPTION_

class FUISMaths {
public:
	int gcd(int x, int y) {
		while (y != 0) {
			Asteps += 3;
			int z = x % y;
			x = y;
			y = z;
		}
		return x;
	};
	int phi(unsigned int n)
	{
		unsigned int result = 1;
		for (int i = 2; i < n; i++)
			if (gcd(i, n) == 1)
				result++;
		return result;
	}

	/**
	* Fast Modular Exponentiation
	* Input: factor, power, modulus
	* Output: factor^power % modulus
	*/
	int fastermod(int factor, int power, int modulus) {
		int result = 1;
		while (power > 0) {
			Asteps += 3;
			if (power % 2 == 1) {
				result = (result*factor) % modulus;
				power = power - 1;
			}
			power = power / 2;
			factor = (factor*factor) % modulus;
		}
		return result;
	};

	/**
	* Fermat Primality Test
	* Input: a single integer we want to test (inputNum)
	* Output: TRUE if prime, FALSE if composite
	* Stolen from some randy ass site
	*/
	int isPrime(int inputNum) {
		// step counter
		Asteps += 1;

		// run through numTrials
		for (int trial = 0; trial < numTrials; trial++) {
			// increment step counter
			Asteps += 6;

			// generate a between 1 and inputNum - 1
			int randTest = floor((rand()*(inputNum - 3))) + 2;

			// check if common factor exists
			if (gcd(randTest, inputNum) != 1) {
				// factor was found, therefore composite
				return false;
			}

			// fermat test
			if (fastermod(randTest, inputNum - 1, inputNum) != 1) {
				// must be composite
				return false;
			}

		} // end for loop

		return true;
	};
protected:
	int numTrials = 20;
	int Asteps = 1;
};



class FUISEncryption: public FUISMaths {
public:
	int encrypt(std::string memLoc) {

		int publicKey;
		int privateKey;

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
		
		roottime = (sqrt(2)*decimaltime)*_TYPE_LENGTH_;
		rootaddress = (sqrt(2)*decimaladdress)*_TYPE_LENGTH_;

		while (isPrime(rootaddress) != true) {
			rootaddress++;
			if (repeatStopAddress == rootaddress) {
				rootaddress++;
			}
		}
		while (isPrime(roottime) != true) {
			roottime++;
			if (repeatStopTime == roottime) {
				roottime++;
			}if (roottime == rootaddress) {
				roottime++;
			}
		}


		repeatStopTime = roottime;
		repeatStopAddress = rootaddress;


		publicKey = rootaddress * roottime;

		

		return publicKey, privateKey;
	};																	//FUIS encryption ends

	void decrypt() {






	};
protected:
	long int i = 0;
	double rootaddress;
	double roottime;
	double repeatStopTime;
	double repeatStopAddress;
	std::string binaryaddress = "";
};


#endif //__!_KGFR_ENCRIPTION_