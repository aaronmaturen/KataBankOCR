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
	std::string lineOne   = "   ";
	std::string lineTwo   = "   ";
	std::string lineThree = "   ";
	std::string lineFour  = "   ";
	CHECK_EQUAL(o.processScannedCharacter(lineOne,lineTwo,lineThree,lineFour),'?');
}

TEST(OCR, TestScannedNumberOne){
	OCR o;
	std::string lineOne   = "   ";
	std::string lineTwo   = "  |";
	std::string lineThree = "  |";
	std::string lineFour  = "   ";
	CHECK_EQUAL(o.processScannedCharacter(lineOne,lineTwo,lineThree,lineFour),'1');
}

TEST(OCR, TestScannedNumberTwo){
	OCR o;
	std::string lineOne   = " _ ";
	std::string lineTwo   = " _|";
	std::string lineThree = "|_ ";
	std::string lineFour  = "   ";
	CHECK_EQUAL(o.processScannedCharacter(lineOne,lineTwo,lineThree,lineFour),'2');
}

TEST(OCR, TestScannedNumberThree){
	OCR o;
	std::string lineOne   = " _ ";
	std::string lineTwo   = " _|";
	std::string lineThree = " _|";
	std::string lineFour  = "   ";
	CHECK_EQUAL(o.processScannedCharacter(lineOne,lineTwo,lineThree,lineFour),'3');
}

TEST(OCR, TestScannedNumberFour){
	OCR o;
	std::string lineOne   = "   ";
	std::string lineTwo   = "|_|";
	std::string lineThree = "  |";
	std::string lineFour  = "   ";
	CHECK_EQUAL(o.processScannedCharacter(lineOne,lineTwo,lineThree,lineFour),'4');
}

TEST(OCR, TestScannedNumberFive){
	OCR o;
	std::string lineOne   = " _ ";
	std::string lineTwo   = "|_ ";
	std::string lineThree = " _|";
	std::string lineFour  = "   ";
	CHECK_EQUAL(o.processScannedCharacter(lineOne,lineTwo,lineThree,lineFour),'5');
}

TEST(OCR, TestScannedNumberSix){
	OCR o;
	std::string lineOne   = " _ ";
	std::string lineTwo   = "|_ ";
	std::string lineThree = "|_|";
	std::string lineFour  = "   ";
	CHECK_EQUAL(o.processScannedCharacter(lineOne,lineTwo,lineThree,lineFour),'6');
}

TEST(OCR, TestScannedNumberSeven){
	OCR o;
	std::string lineOne   = " _ ";
	std::string lineTwo   = "  |";
	std::string lineThree = "  |";
	std::string lineFour  = "   ";
	CHECK_EQUAL(o.processScannedCharacter(lineOne,lineTwo,lineThree,lineFour),'7');
}

TEST(OCR, TestScannedNumberEight){
	OCR o;
	std::string lineOne   = " _ ";
	std::string lineTwo   = "|_|";
	std::string lineThree = "|_|";
	std::string lineFour  = "   ";
	CHECK_EQUAL(o.processScannedCharacter(lineOne,lineTwo,lineThree,lineFour),'8');
}

TEST(OCR, TestScannedNumberNine){
	OCR o;
	std::string lineOne   = " _ ";
	std::string lineTwo   = "|_|";
	std::string lineThree = "  |";
	std::string lineFour  = "   ";
	CHECK_EQUAL(o.processScannedCharacter(lineOne,lineTwo,lineThree,lineFour),'9');
}

TEST(OCR, TestScannedNumberZero){
	OCR o;
	std::string lineOne   = " _ ";
	std::string lineTwo   = "| |";
	std::string lineThree = "|_|";
	std::string lineFour  = "   ";
	CHECK_EQUAL(o.processScannedCharacter(lineOne,lineTwo,lineThree,lineFour),'0');
}

TEST(OCR, TestStringOfIncrementalNumbers){
	OCR o;
	std::string lineOne   = "    _  _     _  _  _  _  _ ";
	std::string lineTwo   = "  | _| _||_||_ |_   ||_||_|";
	std::string lineThree = "  ||_  _|  | _||_|  ||_|  |";
	std::string lineFour  = "                           ";
	CHECK_EQUAL(o.convertScannedLines(lineOne, lineTwo, lineThree, lineFour),"123456789");
}

TEST(OCR, TestStringOfRandomNumbers){
	OCR o;
	std::string lineOne   = " _  _  _  _  _  _  _  _  _ ";
	std::string lineTwo   = "  || | _||_||_||_   |  ||_|";
	std::string lineThree = "  ||_| _|  |  ||_|  |  |  |";
	std::string lineFour  = "                           ";
	CHECK_EQUAL(o.convertScannedLines(lineOne, lineTwo, lineThree, lineFour),"703996779");
}

TEST(OCR, binary){
	OCR o;
	CHECK_EQUAL(o.bin2dec("0"),0);
	CHECK_EQUAL(o.bin2dec("10"),2);
	CHECK_EQUAL(o.bin2dec("101010101010"),2730);
	CHECK_EQUAL(o.bin2dec("101010101010101010101010"),11184810);
}

TEST(OCR, TestGoodAccount){
	OCR o;
	CHECK_EQUAL(o.validateAccount("457508000"),"");
}

TEST(OCR, TestAccountWithUnkownNumber){
	OCR o;
	CHECK_EQUAL(o.validateAccount("12?456789"),"ILL");
}


