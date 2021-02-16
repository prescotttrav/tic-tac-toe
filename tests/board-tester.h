#pragma once

#include "../src/board.h"
#include "position.h"
#include <stdio.h>
#include <stdlib.h>

void assertMatrixEquality(char actual[BOARD_SIZE][BOARD_SIZE],
                          char expected[BOARD_SIZE][BOARD_SIZE], char *msg) {
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      if (actual[i][j] != expected[i][j]) {
        printf("Assertion failed: %s\n", msg);
        printf("Expected: %c, received: %c; for row, %d, col, %d\n",
               expected[i][j], actual[i][j], i, j);
        exit(-1);
      }
    }
  }
}

void assertPlaceSymbolOnBoard(int row, int col,
                              char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = row, .col = col};
  placeSymbolOnBoard(p, 'X', board);
  if (board[p.row][p.col] != 'X') {
    printf("Assertion failed: Place symbol on board\n");
    printf("Expected: %c, received: %c; for row, %d, col, %d\n", 'X',
           board[p.row][p.col], p.row, p.col);
    exit(-1);
  }
}

void assertPositionIsOutOfBoardBounds(int row, int col) {
  Position p = {.row = row, .col = col};
  _Bool actual = positionIsOutOfBoardBounds(p);
  if (actual != 1) {
    printf("Assertion failed: Position out of board bounds\n");
    printf("Expected: %d, received: %d; for row, %d, col, %d\n", 1, actual,
           p.row, p.col);
    exit(-1);
  }
}

void assertPositionIsInBoardBounds(int row, int col) {
  Position p = {.row = row, .col = col};
  _Bool actual = positionIsOutOfBoardBounds(p);
  if (actual != 0) {
    printf("Assertion failed: Position in board bounds\n");
    printf("Expected: %d, received: %d; for row, %d, col, %d\n", 0, actual,
           p.row, p.col);
    exit(-1);
  }
}

void assertDisplayValueOutOfBoardBounds(int displayVal) {
  _Bool actual = outOfBoardBounds(displayVal);
  if (actual != 1) {
    printf("Assertion failed: display value out of board bounds\n");
    printf("Expected: %d, received: %d; for display value %d\n", 1, actual,
           displayVal);
    exit(-1);
  }
}

void assertDisplayValueInBoardBounds(int displayVal) {
  _Bool actual = outOfBoardBounds(displayVal);
  if (actual != 0) {
    printf("Assertion failed: display value in board bounds\n");
    printf("Expected: %d, received: %d; for display value %d\n", 0, actual,
           displayVal);
    exit(-1);
  }
}
