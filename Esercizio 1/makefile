CC=gcc  #compiler
TARGET=bin/run #target file name
RM=bin/out.csv #file to delete before new execution

all: lib/library.c misc/compar.c main/main.c
	mkdir -p bin
	$(CC) lib/library.c misc/compar.c main/main.c -o $(TARGET)

clean:
	rm $(RM)
