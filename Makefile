fifteen_puzzle: bin/board.o
	clang++ $^ -o bin/$@ src/main.cc -Wall -std=c++17 -lncurses

board.o: src/board.cc
	clang++ -c $^ -o bin/$@ -Wall -std=c++17

