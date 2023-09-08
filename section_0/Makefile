CC = gcc
CFLAGS = -std=c99 -g -O2 -Wall -Werror

all: asuna

asuna: asuna.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

asuna.o: asuna.c

clean:
	rm -f asuna *.o

.PHONY: all clean