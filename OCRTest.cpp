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

//TEST(OCR, InitialValueAfterCreationIsValid){
//	OCR o;
//	CHECK(o.faceValue() >= 1);
//	CHECK(o.faceValue() <= 6);
//}
//
//TEST(OCR, ValuesRolledValid){
//	OCR o;
//	for(int i = 0; i < 60000; ++i) {
//		o.roll();
//		CHECK(o.faceValue() >= 1);
//		CHECK(o.faceValue() <= 6);
//	}
//}

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









