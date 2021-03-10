CC = g++
CFLAGS = -I.
OUTPUT = P3
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
	$(CLEANCOMM) *.o

pclean:
	rm P3 output.txt
