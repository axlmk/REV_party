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

options.o: $(PLACE)options/options.c
	$(CC) -o options.o -c $(PLACE)options/options.c $(OPT)

sdd.o: $(PLACE)sdd/sdd.c
	$(CC) -o sdd.o -c $(PLACE)sdd/sdd.c $(OPT)

main.o: $(PLACE)main.c
	$(CC) -o main.o -c $(PLACE)main.c $(OPT)

$(EXEC): main.o options.o sdd.o
#$(EXEC): main.o liste.o element.o
	$(CC) main.o options.o sdd.o -o $(EXEC)
#	$(CC) main.o liste.o element.o -o $(EXEC)

clean:
	rm -rf *.o *.exe *.stackdump
