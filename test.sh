#!/bin/sh

./generator.bin 10 100
./main.bin 10 100 vector.txt matrix.txt
./generator.bin 10 200
./main.bin 10 200 vector.txt matrix.txt
./generator.bin 10 400
./main.bin 10 400 vector.txt matrix.txt
./generator.bin 10 800
./main.bin 10 800 vector.txt matrix.txt
./generator.bin 10 1600
./main.bin 10 1600 vector.txt matrix.txt