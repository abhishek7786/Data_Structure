cc=gcc
cflag=-c -Wall

all: stackexecute

stackexecute: stack.o functions.o
	$(cc) stack.o functions.o -o stack
stack.o: stack.c
	$(cc) $(cflag) stack.c
functions.o: functions.c
	$(cc) $(cflag) functions.c
clean:
	rm -rf *o 
