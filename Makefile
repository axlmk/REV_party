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

trs.o: $(PLACE)uninomial/trs.c
	$(CC) -o trs.o -c $(PLACE)uninomial/trs.c $(OPT)

utils.o: $(PLACE)utils.c
	$(CC) -o utils.o -c $(PLACE)utils.c $(OPT)

graph.o: $(PLACE)graph/graph.c
	$(CC) -o graph.o -c $(PLACE)graph/graph.c $(OPT)

main.o: $(PLACE)main.c
	$(CC) -o main.o -c $(PLACE)main.c $(OPT)

$(EXEC): main.o options.o sdd.o list.o csv.o fptp.o trs.o utils.o graph.o
	$(CC) main.o options.o sdd.o list.o csv.o fptp.o trs.o utils.o graph.o -o $(EXEC)

clean:
	rm -rf *.o *.exe *.stackdump
