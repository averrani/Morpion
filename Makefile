SFML = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

all: main

mark.o: mark.hpp mark.cpp
	g++ -c mark.cpp $(SFML) -Wall

board.o: board.hpp board.cpp 
	g++ -c board.cpp $(SFML) -Wall

main: board.o mark.o main.cpp
	g++ board.o mark.o main.cpp -o main $(SFML)

clean:
	rm main *.o