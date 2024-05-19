CC=gcc  #compiler
TARGET=tests #target file name

all: ../lib/library.c ../misc/compar.c unit_test.c unity.c
	$(CC) ../lib/library.c ../misc/compar.c unit_test.c unity.c -o $(TARGET)

clean:
	rm $(TARGET)
