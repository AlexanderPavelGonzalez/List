CC = g++
CFLAGS = -Wall -std=c++11
OBJS =  testAList.o
EXE = list

$(EXE) : $(OBJS) 
	$(CC) $(OBJS) -o $@
	./list
testAList.o: testAList.cpp alist.h
	$(CC) -c $(CFLAGS) testAList.cpp -o $@
clean:
	rm -f $(OBJS) $(EXE) *~
