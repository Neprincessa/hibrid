CC = gcc
LDFLAGS = -lgomp 
TOPDIR=.
CFLAGS = -std=c99 -O3 -Wall -Werror -fopenmp  
CFILES_main = main.c input.c process.c
CFILES_generator = input.c generator.c

all: main.bin generator.bin

main.bin:
	$(CC) $(CFLAGS) -I$(TOPDIR) $(CFILES_main) $(LDFLAGS) -o $@

generator.bin:
	$(CC) $(CFLAGS) -I$(TOPDIR) $(CFILES_generator) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf *.bin