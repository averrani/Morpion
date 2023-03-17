SFML = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

SRC = src
OBJ = obj
BIN = bin

all: make_dir make_dir2 Morpion

make_dir:
	test -d $(OBJ) || mkdir -p $(OBJ) 

make_dir2:
	test -d $(BIN) || mkdir -p $(BIN) 

$(OBJ)/mark.o: $(SRC)/mark.hpp $(SRC)/mark.cpp
	g++ -c $(SRC)/mark.cpp $(SFML) -Wall -o $@

$(OBJ)/board.o: $(SRC)/board.hpp $(SRC)/board.cpp 
	g++ -c $(SRC)/board.cpp $(SFML) -Wall -o $@

$(OBJ)/game.o: $(SRC)/game.hpp $(SRC)/game.cpp 
	g++ -c $(SRC)/game.cpp $(SFML) -Wall -o $@

Morpion: $(OBJ)/board.o $(OBJ)/mark.o $(OBJ)/game.o $(SRC)/main.cpp
	g++ $(OBJ)/board.o $(OBJ)/mark.o $(OBJ)/game.o $(SRC)/main.cpp -o $(BIN)/Morpion $(SFML)

clean:
	rm -rf $(OBJ) $(BIN)