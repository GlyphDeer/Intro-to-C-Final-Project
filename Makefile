CC = clang
CFLAGS = -Wall
OBJ = tictactoe

all:
	$(CC) main.c board.c game.c players.c test.c testCompleteGame.c -o $(OBJ)
exec:
	./$(OBJ)
clean:
	rm -rf $(OBJ)
	rm -rf *.o
