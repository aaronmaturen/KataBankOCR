/*
 * OCR.cpp
 *
 *  Created on: Nov 28, 2011
 *      Author: Aaron Maturen
 */

#include "OCR.h"
#include <iostream>

OCR::OCR() {
	numbers[0] = 1400;
	numbers[1] = 72;
	numbers[2] = 1264;
	numbers[3] = 1240;
	numbers[4] = 456;
	numbers[5] = 1432;
	numbers[6] = 1464;
	numbers[7] = 1096;
	numbers[8] = 1528;
	numbers[9] = 1496;
}

OCR::~OCR() {

}

std::string OCR::parseLine(std::string line){
	std::string lineCode = "";
	for(std::string::const_iterator it = line.begin(); it != line.end(); ++it){
		lineCode += ((*it==' ')?"0":"1");
	}
	return lineCode;
}

std::bitset<12> OCR::newBitStream(std::string seed){
	std::bitset<12> aBitset (seed);
	return aBitset;
}

std::bitset<12> OCR::newBitStream(std::bitset<12> seed){
	return seed;
}

std::bitset<12> OCR::newBitStream(int seed){
	std::bitset<12> aBitset (seed);
	return aBitset;
}

int OCR::bin2dec(std::string seed){
	return newBitStream(seed).to_ulong();
}

std::string OCR::dec2bin(int const seed){
	return newBitStream(seed).to_string();
}

std::string OCR::serializeScannedCharacter(std::string lineOne, std::string lineTwo, std::string lineThree, std::string lineFour){
	return parseLine(lineOne) + parseLine(lineTwo) + parseLine(lineThree) + parseLine(lineFour);
}

int OCR::compareBitStreams(std::bitset<12> first, std::bitset<12> second){
	return (first^=second).count();
}

std::string OCR::convertScannedLines(std::string lineOne, std::string lineTwo, std::string lineThree, std::string lineFour){
	std::string scannedLine = "";
	for(int k = 0; k < 9; k++){
		scannedLine += processScannedCharacter(lineOne.substr(k*3,3),lineTwo.substr(k*3,3),lineThree.substr(k*3,3),lineFour.substr(k*3,3));
	}
	return scannedLine;
}

char OCR::processScannedCharacter(std::string lineOne, std::string lineTwo, std::string lineThree, std::string lineFour){
	return translateScannedCharacter(bin2dec(serializeScannedCharacter(lineOne,lineTwo,lineThree,lineFour)));
}

bool OCR::checkAccountForMissingValues(std::string accountNumber){
	if(accountNumber.find("?")!=std::string::npos){
		return false;
	} else {
		return true;
	}
}

int OCR::processCheckSum(std::string accountNumber){
	int i = 0;
	int sum = 0;
	for(std::string::const_iterator it = accountNumber.end(); it >= accountNumber.begin(); --it){
		sum += ((*it!='?')?(*it -48):0) * i++;
	}
	return sum % 11;
}

std::string OCR::formatMultipleAMBSolutions(std::string accountNumber,std::string returnString){
	if(returnString == " AMB ["){
		returnString = accountNumber + " ILL";
	}else if(returnString.size() == 19){
		returnString = returnString.substr(7,9);
	}else{
		returnString = accountNumber + returnString.substr(0,returnString.size()-2) + "]";
	}
	return returnString;
}

std::string OCR::fixMissingDigit(std::string accountNumber){
	std::string returnString = "";
	std::string anAccountNumber;
	int location;
	switch(countUnknownCharacters(accountNumber)){
	case 0:
		returnString = accountNumber;
		break;
	case 1:
		returnString = " AMB [";
		location = accountNumber.find('?') + 1;
		for(int i = 0; i <= 9; i++){
			anAccountNumber = accountNumber;
			anAccountNumber[location-1] = char(48+i);
			if(processCheckSum(anAccountNumber) == 0){
				returnString += "'" + anAccountNumber + "', ";
			}
		}
		returnString = formatMultipleAMBSolutions(accountNumber, returnString);
		break;
	default:
		returnString = accountNumber + " ILL";
		break;
	}

	return returnString;
}

std::string OCR::fixBadCheckSum(std::string accountNumber){
	std::string returnString = " AMB [";
	std::string anAccountNumber;
	for(int j = 0; j<=9; j++){
		for(int i = 0; i <= 9; i++){
			if(compareBitStreams(newBitStream(numbers[j]),newBitStream(numbers[int(accountNumber[i])-48])) == 1){
				anAccountNumber = accountNumber;
				anAccountNumber[i] = char(48+j);
				if(processCheckSum(anAccountNumber) == 0){
					returnString += "'" + anAccountNumber + "', ";
				}
			}
		}
	}

	return formatMultipleAMBSolutions(accountNumber, returnString);
}

bool OCR::checkAccountSum(std::string accountNumber){
	if(processCheckSum(accountNumber) == 0){
		return true;
	} else {
		return false;
	}
}

int OCR::countUnknownCharacters(std::string s){
	return std::count(s.begin(), s.end(), '?');
}

std::string OCR::validateAccount(std::string accountNumber){
	if(!checkAccountForMissingValues(accountNumber)){
			return " ILL";
	}else if(!checkAccountSum(accountNumber)){
		return " ERR";
	}else {
		return "";
	}
}

char OCR::translateScannedCharacter(int scannedCharacter){
	int value = 63;
	for(int i=0;i<10;i++){
		value = ((numbers[i]==scannedCharacter) ? i + 48: value);
	}
	return char(value);
}
