CC = g++
CFLAGS = -I.
OUTPUT = P3
DEPENDANCIES = main.o

CLEANCOMM = rm -f

%.o: %.cpp
	$(CC) -std=c++11 -c -g -o $@ $< $(CFLAGS)

$(OUTPUT): $(DEPENDANCIES)
	$(CC) -std=c++11 -Wall -g -o $@ $^
	make clean

clean:
	$(CLEANCOMM) *.o

pclean:
	$(CLEANCOMM) *.o P3 output.txt
