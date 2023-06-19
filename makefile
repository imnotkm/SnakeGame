run:
	g++ -o play ./src/map.cpp ./src/coordinate.cpp ./src/snake_game.cpp  ./src/stage.cpp -lncurses
	./play