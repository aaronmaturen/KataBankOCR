CC=g++
CXXFLAGS=-Wall -ansi -pedantic
CPPUTEST = ../CPPUTest-v3.3


all: clean RunAllTests

main: main.o OCR.o

test: RunAllTests

RunAllTests: LDFLAGS=-lCppUTest
RunAllTests: LDLIBS=-L $(CPPUTEST)/lib
RunAllTests: CXXFLAGS += -I $(CPPUTEST)/include
RunAllTests: RunAllTests.o OCRTest.o OCR.o

clean: clean_test clean_main

clean_test: clean_bits
	rm -f RunAllTests

clean_main: clean_bits
	rm -f main

clean_bits:
	rm -rf a.out *.o
