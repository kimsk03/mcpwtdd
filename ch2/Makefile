CC = g++
INC = -I../googletest/include/
LIB = -L../googletest/lib/
LIB += -lgmock_main
FLAG += -std=c++14 

all:
	$(CC) $(FLAG) -o soundex soundextest.cpp $(INC) $(LIB) 

clean:
	rm soundex
