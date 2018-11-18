CC=gcc
OPT=-Wall
EXEC=scrutin
PLACE=src/

#exemple
all:$(EXEC)

#element.o: element.c
#	$(CC) -o element.o -c element.c $(OPT)
#liste.o: liste.c
# etc

option.o: $(PLACE)option/option.c
	$(CC) -o option.o -c $(PLACE)option/option.c $(OPT)

main.o: $(PLACE)main.c
	$(CC) -o main.o -c $(PLACE)main.c $(OPT)

$(EXEC): main.o option.o
#$(EXEC): main.o liste.o element.o
	$(CC) main.o option.o -o $(EXEC)
#	$(CC) main.o liste.o element.o -o $(EXEC)

clean:
	rm -rf *.o *.exe *.stackdump
