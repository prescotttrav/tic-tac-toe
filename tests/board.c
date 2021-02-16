#include "../board.h"
#include "board-tester.h"

void testInitializeBoard() {
  char boardOne[BOARD_SIZE][BOARD_SIZE];
  char boardTwo[BOARD_SIZE][BOARD_SIZE] = {
      {'9', '8', '7'}, {'6', '5', '4'}, {'3', '2', '1'}};
  char expected[BOARD_SIZE][BOARD_SIZE] = {
      {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

  initializeBoard(boardOne);
  assertMatrixEquality(boardOne, expected, "Uninitialized board");

  initializeBoard(boardTwo);
  assertMatrixEquality(boardTwo, expected, "Initialized board");
}

void testPlaceSymbolOnBoard() {
  char testBoard[BOARD_SIZE][BOARD_SIZE];
  initializeBoard(testBoard);

  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      assertPlaceSymbolOnBoard(i, j, testBoard);
    }
  }
}

void testOutOfBoardBounds() {
  int i;
  for (i = -3; i < 1; ++i) {
    assertDisplayValueOutOfBoardBounds(i);
  }

  for (i = 1; i <= BOARD_SIZE * BOARD_SIZE; ++i) {
    assertDisplayValueInBoardBounds(i);
  }

  for (i = BOARD_SIZE * BOARD_SIZE + 1; i < BOARD_SIZE * BOARD_SIZE + 4; ++i) {
    assertDisplayValueOutOfBoardBounds(i);
  }
}

void testPositionIsOutOfBoardBounds() {
  for (int i = -BOARD_SIZE; i < 0; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      assertPositionIsOutOfBoardBounds(i, j);
    }
  }

  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      assertPositionIsInBoardBounds(i, j);
    }
  }

  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = -BOARD_SIZE; j < 0; ++j) {
      assertPositionIsOutOfBoardBounds(i, j);
    }
  }
}

void testBoardUtils() {
  testInitializeBoard();
  testPlaceSymbolOnBoard();
  testOutOfBoardBounds();
  testPositionIsOutOfBoardBounds();
}
