CC=gcc

DEPS=src/main.h src/board.h src/display.h src/playerMove.h src/position.h src/validateWinner.h 
OBJ=src/main.o src/board.o src/display.o src/playerMove.o src/position.o src/validateWinner.o

TEST_DEPS=src/board.h tests/board.h tests/board-tester.h src/board.h src/position.h tests/position.h tests/position-tester.h src/validateWinner.h tests/validateWinner.h tests/validateWinner-tester.h
TEST_OBJ=src/board.o tests/board.o tests/main.o src/position.o tests/position.o src/validateWinner.o tests/validateWinner.o

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

tictactoe: $(OBJ) 
	$(CC) -g -o $@ $^ $(CFLAGS)

%.o: %.c $(TEST_DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

.PHONY: clean test

test: $(TEST_OBJ)
	$(CC) -g -o $@.exe $^ $(CFLAGS)

clean:
	rm -f *.o tests/*.o tictactoe test.exe 
