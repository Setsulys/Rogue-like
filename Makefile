#Makefile TP1
CC = gcc
CFLAGS =  -Wall -g #-ansi
LDFLAGS = -lMLV
OBJ = src/labyrinthe.o src/graphique.o src/objetslab.o src/devtools.o src/labyrinthe_expand.o src/labyrinthe_creation.o src/etage.o src/save.o src/load.o src/Combat.o src/Inventaire.o src/Potion.o src/Personnage.o


EXEC=labyrinthe


all:	
	make clean
	make $(EXEC)
	mv $(OBJ) obj
	mv ./$(EXEC) bin
	bin/./$(EXEC)
	


$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LDFLAGS)

clean:
	rm -f prog obj/*.o

delete:
	-rm $(EXEC)	
