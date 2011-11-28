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
	char numberTwo[4][3] = {{' ','_',' '},{' ','_','|'},{'_','_',' '},{' ',' ',' '}};
	char numberThree[4][3] = {{' ','_',' '},{' ','_','|'},{' ','_','|'},{' ',' ',' '}};
	char numberFour[4][3] = {{' ',' ',' '},{'|','_','|'},{' ',' ','|'},{' ',' ',' '}};
	char numberFive[4][3] = {{' ','_',' '},{'|','_',' '},{' ','_','|'},{' ',' ',' '}};
	char numberSix[4][3] = {{' ','_',' '},{'|','_',' '},{'|','_','|'},{' ',' ',' '}};
	char numberSeven[4][3] = {{' ','_',' '},{' ',' ','|'},{' ',' ','|'},{' ',' ',' '}};
	char numberEight[4][3] = {{' ','_',' '},{'|','_','|'},{'|','_','|'},{' ',' ',' '}};
	char numberNine[4][3] = {{' ','_',' '},{'|','_','|'},{' ','_','|'},{' ',' ',' '}};
	char numberZero[4][3] = {{' ','_',' '},{'|',' ','|'},{'|','_','|'},{' ',' ',' '}};

	if(compareScannedCharacters(scannedCharacter, numberOne) == true){
		value = '1';
	}else if(compareScannedCharacters(scannedCharacter, numberTwo) == true){
		value = '2';
	}else if(compareScannedCharacters(scannedCharacter, numberThree) == true){
		value = '3';
	}else if(compareScannedCharacters(scannedCharacter, numberFour) == true){
		value = '4';
	}else if(compareScannedCharacters(scannedCharacter, numberFive) == true){
		value = '5';
	}else if(compareScannedCharacters(scannedCharacter, numberSix) == true){
		value = '6';
	}else if(compareScannedCharacters(scannedCharacter, numberSeven) == true){
		value = '7';
	}else if(compareScannedCharacters(scannedCharacter, numberEight) == true){
		value = '8';
	}else if(compareScannedCharacters(scannedCharacter, numberNine) == true){
		value = '9';
	}else if(compareScannedCharacters(scannedCharacter, numberZero) == true){
		value = '0';
	}else{
		value = '?';
	}
	return value;
}
