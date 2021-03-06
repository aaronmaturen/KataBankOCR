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
	std::string lineThree = " _|";
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
	std::string lineThree = "  ||_  _|  | _||_|  ||_| _|";
	std::string lineFour  = "                           ";
	CHECK_EQUAL(o.convertScannedLines(lineOne, lineTwo, lineThree, lineFour),"123456789");
}

TEST(OCR, TestStringOfRandomNumbers){
	OCR o;
	std::string lineOne   = " _  _  _  _  _  _  _  _  _ ";
	std::string lineTwo   = "  || | _||_||_||_   |  ||_|";
	std::string lineThree = "  ||_| _| _| _||_|  |  | _|";
	std::string lineFour  = "                           ";
	CHECK_EQUAL(o.convertScannedLines(lineOne, lineTwo, lineThree, lineFour),"703996779");
}

TEST(OCR, binary){
	OCR o;
	CHECK_EQUAL(o.bin2dec("0"),0);
	CHECK_EQUAL(o.bin2dec("10"),2);
	CHECK_EQUAL(o.bin2dec("101010101010"),2730);
}

TEST(OCR, NewBitset){
	OCR o;
	CHECK_EQUAL(o.dec2bin(51),"000000110011");
}

TEST(OCR, TestGoodAccount){
	OCR o;
	CHECK_EQUAL(o.validateAccount("457508000"),"");
}

TEST(OCR, TestAccountCheckSumWithAnUnkownZero){
	OCR o;
	CHECK_EQUAL(o.processCheckSum("4575080?0"),0);
}

TEST(OCR, TestRandomGoodAccountCheckSum){
	OCR o;
	CHECK_EQUAL(o.processCheckSum("732540941"),0);
}

TEST(OCR, TestFillInMissingDigit){
	OCR o;
	CHECK_EQUAL(o.fixMissingDigit("78?639000"),"784639000");
}

TEST(OCR, TestFillInMissingDigitFromDescription){
	OCR o;
	CHECK_EQUAL(o.fixMissingDigit("?23456789"),"123456789");
}

TEST(OCR, TestFillInAnotherMissingDigit){
	OCR o;
	CHECK_EQUAL(o.fixMissingDigit("7325?0941"),"732540941");
}

TEST(OCR, TestFillInMultipleMissingDigit){
	OCR o;
	CHECK_EQUAL(o.fixMissingDigit("73?5?0941"),"73?5?0941 ILL");
}

TEST(OCR, TestAccountWithUnkownNumber){
	OCR o;
	CHECK_EQUAL(o.validateAccount("12?456789")," ILL");
}

TEST(OCR, TestInvalidCheckSum){
	OCR o;
	CHECK_EQUAL(o.checkAccountSum("664371495"),false);
}

TEST(OCR, TestAccountWithIvalidChecksum){
	OCR o;
	CHECK_EQUAL(o.validateAccount("664371495")," ERR");
}

TEST(OCR, TestComparingBitStreams){
	OCR o;
	CHECK_EQUAL(o.compareBitStreams(o.newBitStream(55),o.newBitStream(55)),0);
}

TEST(OCR, TestComparingBitStreamsOffByOne){
	OCR o;
	CHECK_EQUAL(o.compareBitStreams(o.newBitStream(7),o.newBitStream(6)),1);
}

TEST(OCR, TestComparingBitStreamsFromStringAndInteger){
	OCR o;
	CHECK_EQUAL(o.compareBitStreams(o.newBitStream("110011101001"),o.newBitStream(3305)),0);
}

TEST(OCR, TestComparingBitStreamsExtremeDifferenceInStrings){
	OCR o;
	CHECK_EQUAL(o.compareBitStreams(o.newBitStream("11111"),o.newBitStream("00000")),5);
}

TEST(OCR, TestCountUnknownCharacters){
	OCR o;
	CHECK_EQUAL(o.countUnknownCharacters("0541?????013"),5);
}

TEST(OCR, TestCountZeroUnknownCharacters){
	OCR o;
	CHECK_EQUAL(o.countUnknownCharacters("054112345013"),0);
}

TEST(OCR, TestCountOneUnknownCharacters){
	OCR o;
	CHECK_EQUAL(o.countUnknownCharacters("0541123?5013"),1);
}

TEST(OCR, TestWrongChecksumOneSolution){
	OCR o;
	CHECK_EQUAL(o.fixBadCheckSum("111111111"),"711111111");
}

TEST(OCR, TestWrongChecksumTwoSolutions){
	OCR o;
	CHECK_EQUAL(o.fixBadCheckSum("555555555"),"555555555 AMB ['555655555', '559555555']");
}

TEST(OCR, TestWrongChecksumThreeSolutions){
	OCR o;
	CHECK_EQUAL(o.fixBadCheckSum("888888888"),"888888888 AMB ['888888880', '888886888', '888888988']");
}


