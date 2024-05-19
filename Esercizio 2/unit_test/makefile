CC=gcc  #compiler
TARGET=tests #target file name

all: ../skiplist/skip_list.c ../misc/compar.c unit_test.c unity.c
	$(CC) ../skiplist/skip_list.c ../misc/compar.c unit_test.c unity.c -o $(TARGET)

clean:
	rm $(TARGET)
