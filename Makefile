CPP=g++ --std=c++11

CFLAGS= -Wall

all : mr

mr : main.o Core.o MapReduce.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $<

MapReduce.o : MapReduce.cpp MapReduce.hpp 
	$(CPP) $(CFLAGS) -c $<
Core.o : Core.cpp Core.hpp
	$(CPP) $(CFLAGS) -c $<
clean :
	rm *.o
test:
	./mr