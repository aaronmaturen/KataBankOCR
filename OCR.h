/*
 * OCR.h
 *
 *  Created on: Nov 28, 2011
 *      Author: Aaron Maturen
 */

#ifndef OCR_H_
#define OCR_H_
#pragma once

#include <string>
#include <math.h>

class OCR {
public:
	OCR();
	virtual ~OCR();

//	std::string code;
	std::string parseLine(std::string);
//	bool compareScannedCharacters(char scannedCharacter[4][3], char definedCharacter[4][3]);
//	char convertScannedCharacter(char[4][3]);
	std::string serializeScannedCharacter(std::string, std::string, std::string, std::string);
	char processScannedCharacter(std::string, std::string, std::string, std::string);
	char translateScannedCharacter(int);
	int bin2dec(std::string);
	std::string convertScannedLines(std::string, std::string, std::string, std::string);
//	std::string getCode(void);
};

#endif
