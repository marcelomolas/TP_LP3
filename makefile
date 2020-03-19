SRC = src/capitulo_
INCL = -I src/capitulo_1/1.3/
OBJ = obj/capitulo_
BIN = bin/capitulo_

all: reciproco arglist clean

reciproco: $(OBJ)1/1.1/main.o $(OBJ)1/1.2/reciproco.o
	g++ $(OBJ)1/1.1/main.o $(OBJ)1/1.2/reciproco.o -o $(BIN)1/1.1/reciproco

$(OBJ)1/1.1/main.o: $(SRC)1/1.1/main.c
	gcc -c $(INCL) $(SRC)1/1.1/main.c -o $(OBJ)1/1.1/main.o

$(OBJ)1/1.2/reciproco.o: $(SRC)1/1.2/reciproco.cpp
	g++ -c $(INCL) $(SRC)1/1.2/reciproco.cpp -o $(OBJ)1/1.2/reciproco.o

arglist: $(OBJ)2/2.1/arglist.o
	gcc $(OBJ)2/2.1/arglist.o -o $(BIN)2/2.1/arglist

$(OBJ)2/2.1/arglist.o: $(SRC)2/2.1/arglist.c
	gcc -c $(SRC)2/2.1/arglist.c -o $(OBJ)2/2.1/arglist.o

clean:
	find ./obj -type f -name "*.o" -exec rm -f {} \;
