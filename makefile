blackJackExecutable: main.o deck.o card.o
	g++ -o blackJackExecutable main.o deck.o card.o

main.o: deck.h main.cpp
	g++ -c main.cpp -g

deck.o: card.h deck.h deck.cpp
	g++ -c deck.cpp -g

card.o: card.h card.cpp
	g++ -c card.cpp -g

clean:
	rm *.o blackJackExecutable