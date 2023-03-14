SFML = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

all: main

board.o: board.hpp board.cpp
	g++ -c board.cpp $(SFML)

main: board.o main.cpp
	g++ board.o main.cpp -o main $(SFML)

clean:
	rm main