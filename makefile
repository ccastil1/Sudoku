main: main.o Puzzle.o
	g++ -o main main.o Puzzle.o
main.o: main.cpp
	g++ -c main.cpp
CardDeck.o: Puzzle.cpp
	g++ -c Puzzle.cpp
clean:
	rm *.o main
