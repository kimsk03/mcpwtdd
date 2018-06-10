INCLUDE += -I../googletest/include -I./
LIBRARY += -L../googletest/lib -lgmock_main

all:
	clang++ -std=c++11 $(INCLUDE) $(LIBRARY) -o soundex SoundexTest.cc

clean:
	rm -f soundex
