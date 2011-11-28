/*
 * OCRTest.cpp
 *
 *  Created on: Nov 28, 2011
 *      Author: Aaron Maturen
 */

#include "OCR.h"
#include <CppUTest/TestHarness.h>

TEST_GROUP(OCR) {

};

TEST(OCR, TestEmptyCharacterRecognition){
	OCR o;
	char scannedChar[4][3] = {
			{' ',' ',' '},
			{' ',' ',' '},
			{' ',' ',' '},
			{' ',' ',' '}
	};
	CHECK_EQUAL(o.convertScannedCharacter(scannedChar),'?');
}

TEST(OCR, TestScannedNumberOne){
	OCR o;
	char scannedChar[4][3] = {
			{' ',' ',' '},
			{' ',' ','|'},
			{' ',' ','|'},
			{' ',' ',' '}
	};
	CHECK_EQUAL(o.convertScannedCharacter(scannedChar),'1');
}









