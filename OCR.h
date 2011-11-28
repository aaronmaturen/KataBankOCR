/*
 * OCR.h
 *
 *  Created on: Nov 28, 2011
 *      Author: Aaron Maturen
 */

#ifndef OCR_H_
#define OCR_H_
#pragma once

class OCR {
public:
	OCR();
	virtual ~OCR();

	bool compareScannedCharacters(char scannedCharacter[4][3], char definedCharacter[4][3]);
	char convertScannedCharacter(char scannedCharacter[4][3]);
};

#endif
