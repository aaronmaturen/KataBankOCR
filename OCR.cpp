/*
 * OCR.cpp
 *
 *  Created on: Nov 28, 2011
 *      Author: Aaron Maturen
 */

#include "OCR.h"
#include <iostream>

OCR::OCR() {


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
	std::string::iterator it;
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

bool OCR::checkAccountSum(std::string accountNumber){
	int i = 0;
	int sum = 0;
	for(std::string::const_iterator it = accountNumber.end(); it >= accountNumber.begin(); --it){
		sum += (*it -48) * i++;
	}

	if(sum % 11 == 0){
		return true;
	} else {
		return false;
	}
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
	char value;
	const int numberOne = 72;
	const int numberTwo = 1264;
	const int numberThree = 1240;
	const int numberFour = 456;
	const int numberFive = 1432;
	const int numberSix = 1464;
	const int numberSeven = 1096;
	const int numberEight = 1528;
	const int numberNine = 1480;
	const int numberZero = 1400;

	switch(scannedCharacter){
		case numberOne:
			value = '1';
			break;
		case numberTwo:
			value = '2';
			break;
		case numberThree:
			value = '3';
			break;
		case numberFour:
			value = '4';
			break;
		case numberFive:
			value = '5';
			break;
		case numberSix:
			value = '6';
			break;
		case numberSeven:
			value = '7';
			break;
		case numberEight:
			value = '8';
			break;
		case numberNine:
			value = '9';
			break;
		case numberZero:
			value = '0';
			break;
		default:
			value = '?';
			break;
	}
	return value;
}
