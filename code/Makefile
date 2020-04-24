CC=g++
CFLAGS= -std=c++17 -Wall -w -g
OFLAGS= -g -c
OBJS=main.o complex.o
EXE=output


$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)


main.o: main.cc
	$(CC) $(OFLAGS) main.cc

complex.o: complex.cc
	$(CC) $(OFLAGS) complex.cc
	
clean:
	rm *.o output

cleanEmacs:
	rm *~
run: $(EXE)
	./output

redo: 
	make clean
	make run
