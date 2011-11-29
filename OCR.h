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

	std::string parseLine(std::string);
	std::string serializeScannedCharacter(std::string, std::string, std::string, std::string);
	char processScannedCharacter(std::string, std::string, std::string, std::string);
	char translateScannedCharacter(int);
	int bin2dec(std::string);
	std::string convertScannedLines(std::string, std::string, std::string, std::string);
	std::string validateAccount(std::string);
};

#endif
