CC=gcc
OPT=-Wall
EXEC=revParty

#exemple
all:$(EXEC)

#element.o: element.c
#	$(CC) -o element.o -c element.c $(OPT)
#liste.o: liste.c
# etc

main.o: main.c
	$(CC) -o main.o -c main.c

#$(EXEC): main.o liste.o element.o
#	$(CC) main.o liste.o element.o -o $(EXEC)

#clean:
#	rm -rf *.o *.exe *.stackdump

