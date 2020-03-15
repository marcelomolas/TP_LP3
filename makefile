SRC = src/capitulo_1/1.1/
SRC2 = src/capitulo_1/1.2/
INCL = -I src/capitulo_1/1.3/
OBJ = obj/capitulo_1/1.1/main.o
OBJ2 = obj/capitulo_1/1.2/reciproco.o
EXEC = bin/capitulo_1/1.1/reciproco

reciproco: $(OBJ) $(OBJ2)
	g++ $(OBJ) $(OBJ2) -o $(EXEC)

$(OBJ): $(SRC)main.c
	gcc -c $(INCL) $(SRC)main.c -o $(OBJ)

$(OBJ2): $(SRC2)reciproco.cpp
	g++ -c $(INCL) $(SRC2)reciproco.cpp -o $(OBJ2)

