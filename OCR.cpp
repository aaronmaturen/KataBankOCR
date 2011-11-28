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

int OCR::faceValue() const{
	return 1;
}

char OCR::convertScannedCharacter(char scannedCharacter[4][3]){
	return '?';
}
