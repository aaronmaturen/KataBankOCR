/*
 * OCR.cpp
 *
 *  Created on: Nov 28, 2011
 *      Author: Aaron Maturen
 */

#include "OCR.h"

OCR::OCR() {


}

OCR::~OCR() {

}

bool OCR::compareScannedCharacters(char scannedCharacter[4][3], char definedCharacter[4][3]){
	bool flag = true;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
			if(scannedCharacter[i][j] != definedCharacter[i][j]){
				flag = false;
			}
		}
	}
	return flag;
}

char OCR::convertScannedCharacter(char scannedCharacter[4][3]){
	char value;
	char numberOne[4][3] = {{' ',' ',' '},{' ',' ','|'},{' ',' ','|'},{' ',' ',' '}};

	if(compareScannedCharacters(scannedCharacter, numberOne) == true){
		value = '1';
	}else{
		value = '?';
	}
	return value;
}
