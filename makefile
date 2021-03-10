CC = g++
CFLAGS = -I.
OUTPUT = P1
DEPENDANCIES = main.o

ifeq ($(OS), Windows_NT)
	CLEANCOMM = del /Q /S
else
	CLEANCOMM = rm -f
endif

%.o: %.cpp
	$(CC) -std=c++11 -c -g -o $@ $< $(CFLAGS)

$(OUTPUT): $(DEPENDANCIES)
	$(CC) -std=c++11 -Wall -g -o $@ $^
	make clean

clean:
	$(CLEANCOMM) *.o P3 output.txt
