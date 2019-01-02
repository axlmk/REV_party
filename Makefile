CC=gcc
OPT=-Wall
EXEC=scrutin
PLACE=src/

all:$(EXEC)

csv.o: $(PLACE)csv/import_csv.c
	$(CC) -o csv.o -c $^ $(OPT)

list.o: $(PLACE)sdd/list.c
	$(CC) -o list.o -c $^ $(OPT)

options.o: $(PLACE)options/options.c
	$(CC) -o options.o -c $^ $(OPT)

sdd.o: $(PLACE)sdd/sdd.c
	$(CC) -o sdd.o -c $^ $(OPT)

fptp.o: $(PLACE)voting_methods/uninomial/fptp.c
	$(CC) -o fptp.o -c $^ $(OPT)

trs.o: $(PLACE)voting_methods/uninomial/trs.c
	$(CC) -o trs.o -c $^ $(OPT)

utils.o: $(PLACE)utils.c
	$(CC) -o utils.o -c $^ $(OPT)

graph.o: $(PLACE)graph/graph.c
	$(CC) -o graph.o -c $^ $(OPT)

condorcet.o: $(PLACE)voting_methods/condorcet/condorcet.c
	$(CC) -o condorcet.o -c $^ $(OPT)

minimax.o: $(PLACE)voting_methods/condorcet/minimax.c
	$(CC) -o minimax.o -c $^ $(OPT)

rankedpairs.o: $(PLACE)voting_methods/condorcet/rankedpairs.c
	$(CC) -o rankedpairs.o -c $^ $(OPT)

circuit.o: $(PLACE)circuit/circuit.c
	$(CC) -o circuit.o -c $^ $(OPT)

irv.o: $(PLACE)voting_methods/irv.c
	$(CC) -o irv.o -c $^ $(OPT)

main.o: $(PLACE)main.c
	$(CC) -o main.o -c $(PLACE)main.c $(OPT)

$(EXEC): main.o options.o sdd.o list.o csv.o fptp.o trs.o utils.o graph.o condorcet.o minimax.o rankedpairs.o circuit.o irv.o
	$(CC) $^ -o $(EXEC)

clean:
	rm -rf *.o *.exe *.stackdump
