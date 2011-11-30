/*
 * main.cpp
 *
 *  Created on: Nov 30, 2011
 *      Author: atmature
 */

#include "OCR.h"
#include <fstream>
#include <iostream>
int main(int argc, char **argv) {
	OCR o;
	std::string line1, line2, line3, line4;
	std::string accountNumber;
	std::ifstream filestr ("test.input");
	std::ofstream story3 ("story3.txt");
	if(filestr.is_open()){
		while(filestr.good()){
			getline (filestr, line1);
			getline (filestr, line2);
			getline (filestr, line3);
			getline (filestr, line4);

			//user story 1
			std::cout << line1 <<std::endl;
			std::cout << line2 <<std::endl;
			std::cout << line3 <<std::endl;
			std::cout << line4 <<std::endl;
			accountNumber = o.convertScannedLines(line1, line2, line3, line4);

			//user story 2
			std::cout << std::endl << "=> " << accountNumber;
			std::cout << ((o.processCheckSum(accountNumber)==0) ? " valid":" invalid") << " checksum" << std::endl;

			//user story 3
			if (story3.is_open()){
				story3 << accountNumber << o.validateAccount(accountNumber) << std::endl;
			}
		}
	}



	filestr.close();
	story3.close();
} //end main


