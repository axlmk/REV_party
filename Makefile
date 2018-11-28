CC=gcc
OPT=-Wall
EXEC=scrutin
PLACE=src/

all:$(EXEC)

csv.o: $(PLACE)csv/import_csv.c
	$(CC) -o csv.o -c $(PLACE)csv/import_csv.c $(OPT)

list.o: $(PLACE)sdd/list.c
	$(CC) -o list.o -c $(PLACE)sdd/list.c $(OPT)

options.o: $(PLACE)options/options.c
	$(CC) -o options.o -c $(PLACE)options/options.c $(OPT)

sdd.o: $(PLACE)sdd/sdd.c
	$(CC) -o sdd.o -c $(PLACE)sdd/sdd.c $(OPT)

main.o: $(PLACE)main.c
	$(CC) -o main.o -c $(PLACE)main.c $(OPT)

$(EXEC): main.o options.o sdd.o list.o csv.o
	$(CC) main.o options.o sdd.o list.o csv.o -o $(EXEC)

clean:
	rm -rf *.o *.exe *.stackdump
