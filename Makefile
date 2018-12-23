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

fptp.o: $(PLACE)uninomial/fptp.c
	$(CC) -o fptp.o -c $(PLACE)uninomial/fptp.c $(OPT)

utils.o: $(PLACE)utils.c
	$(CC) -o utils.o -c $(PLACE)utils.c $(OPT)

main.o: $(PLACE)main.c
	$(CC) -o main.o -c $(PLACE)main.c $(OPT)

$(EXEC): main.o options.o sdd.o list.o csv.o fptp.o utils.o
	$(CC) main.o options.o sdd.o list.o csv.o fptp.o utils.o -o $(EXEC)

clean:
	rm -rf *.o *.exe *.stackdump
