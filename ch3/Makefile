CC = g++
INC = -I../googletest/include/
LIB = -L../googletest/lib/
LIB += -lgmock_main
FLAG += -std=c++14

all:
	$(CC) $(FLAG) -o retweet RetweetCollectionTest.cpp $(INC) $(LIB)

clean:
	rm retweet
