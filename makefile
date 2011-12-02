CC=g++
CXXFLAGS=-Wall -ansi -pedantic -I ../CppUTest-v2.3/include
LDFLAGS=-lCppUTest
LDLIBS=-L ../CPPUTest-v2.3/lib

all: clean RunAllTests

RunAllTests: RunAllTests.o OCRTest.o OCR.o

clean:
	rm -rf a.out *.o test
