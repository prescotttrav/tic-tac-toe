CC=gcc

DEPS=main.h board.h display.h playerMove.h position.h validateWinner.h 
OBJ=main.o board.o display.o playerMove.o position.o validateWinner.o

TEST_DEPS=board.h tests/board.h tests/board-tester.h board.h position.h tests/position.h tests/position-tester.h validateWinner.h tests/validateWinner.h tests/validateWinner-tester.h
TEST_OBJ=board.o tests/board.o tests/main.o position.o tests/position.o validateWinner.o tests/validateWinner.o

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
	rm -f *.o tests/*.o tictactoe test 
