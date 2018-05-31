CC = g++
INC = -I../googletest/include/
LIB = -L../googletest/lib/
LIB += -lgmock_main
FLG += -std=c++14

all:
	$(CC) $(FLG) -o Soundex SoundexTest.cpp $(INC) $(LIB)

clean:
	rm Soundex
