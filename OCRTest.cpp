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

TEST(OCR, TestScannedNumberTwo){
	OCR o;
	char scannedChar[4][3] = {
			{' ','_',' '},
			{' ','_','|'},
			{'_','_',' '},
			{' ',' ',' '}
	};
	CHECK_EQUAL(o.convertScannedCharacter(scannedChar),'2');
}

TEST(OCR, TestScannedNumberThree){
	OCR o;
	char scannedChar[4][3] = {
			{' ','_',' '},
			{' ','_','|'},
			{' ','_','|'},
			{' ',' ',' '}
	};
	CHECK_EQUAL(o.convertScannedCharacter(scannedChar),'3');
}

TEST(OCR, TestScannedNumberFour){
	OCR o;
	char scannedChar[4][3] = {
			{' ',' ',' '},
			{'|','_','|'},
			{' ',' ','|'},
			{' ',' ',' '}
	};
	CHECK_EQUAL(o.convertScannedCharacter(scannedChar),'4');
}

TEST(OCR, TestScannedNumberFive){
	OCR o;
	char scannedChar[4][3] = {
			{' ','_',' '},
			{'|','_',' '},
			{' ','_','|'},
			{' ',' ',' '}
	};
	CHECK_EQUAL(o.convertScannedCharacter(scannedChar),'5');
}

TEST(OCR, TestScannedNumberSix){
	OCR o;
	char scannedChar[4][3] = {
			{' ','_',' '},
			{'|','_',' '},
			{'|','_','|'},
			{' ',' ',' '}
	};
	CHECK_EQUAL(o.convertScannedCharacter(scannedChar),'6');
}

TEST(OCR, TestScannedNumberSeven){
	OCR o;
	char scannedChar[4][3] = {
			{' ','_',' '},
			{' ',' ','|'},
			{' ',' ','|'},
			{' ',' ',' '}
	};
	CHECK_EQUAL(o.convertScannedCharacter(scannedChar),'7');
}

TEST(OCR, TestScannedNumberEight){
	OCR o;
	char scannedChar[4][3] = {
			{' ','_',' '},
			{'|','_','|'},
			{'|','_','|'},
			{' ',' ',' '}
	};
	CHECK_EQUAL(o.convertScannedCharacter(scannedChar),'8');
}

TEST(OCR, TestScannedNumberNine){
	OCR o;
	char scannedChar[4][3] = {
			{' ','_',' '},
			{'|','_','|'},
			{' ','_','|'},
			{' ',' ',' '}
	};
	CHECK_EQUAL(o.convertScannedCharacter(scannedChar),'9');
}

TEST(OCR, TestScannedNumberZero){
	OCR o;
	char scannedChar[4][3] = {
			{' ','_',' '},
			{'|',' ','|'},
			{'|','_','|'},
			{' ',' ',' '}
	};
	CHECK_EQUAL(o.convertScannedCharacter(scannedChar),'0');
}





