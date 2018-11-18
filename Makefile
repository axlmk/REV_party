CC=gcc
OPT=-Wall
EXEC=revParty
PLACE=src/

#exemple
all:$(EXEC)

#element.o: element.c
#	$(CC) -o element.o -c element.c $(OPT)
#liste.o: liste.c
# etc

main.o: $(PLACE)main.c
	$(CC) -o main.o -c $(PLACE)main.c

$(EXEC): main.o
#$(EXEC): main.o liste.o element.o
	$(CC) main.o -o $(EXEC)
#	$(CC) main.o liste.o element.o -o $(EXEC)

clean:
	rm -rf *.o *.exe *.stackdump
