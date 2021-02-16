#pragma once

#include "../src/board.h"
#include "../src/validateWinner.h"
#include <stdio.h>
#include <stdlib.h>

void assertInitializeVisitedPositions(Position p) {
  Position visited[BOARD_SIZE * BOARD_SIZE];
  Position emptyP = {.row = -1, .col = -1};

  initializeVisitedPositions(p, visited);
  if (!positionEquality(p, visited[0])) {
    printf("Assertion failed: initialize visited positions with proper first "
           "element.\n");
    printf("Expected: { row = %d, col = %d }, received: { row = %d, col = %d "
           "}; for index %d\n",
           visited[0].row, visited[0].col, p.row, p.col, 0);
    exit(-1);
  }

  for (int i = 1; i < BOARD_SIZE * BOARD_SIZE; ++i) {
    if (!positionEquality(emptyP, visited[i])) {
      printf("Assertion failed: initialize visited positions with empty empty "
             "element\n");
      printf("Expected: { row = %d, col = %d }, received: { row = %d, col = %d "
             "}; for index %d\n",
             visited[i].row, visited[i].col, p.row, p.col, i);
      exit(-1);
    }
  }
}

void assertNoHorizontalAdjacentSimilarElements(
    Position visited[BOARD_SIZE * BOARD_SIZE],
    char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = 0, .col = 0};
  initializeVisitedPositions(p, visited);

  int actual =
      adjacentSimilarElements(0, HORIZONTAL, 'X', p, 1, visited, board);
  if (actual != 2) {
    printf("Assertion failed: no adjacent similar elements on horizontal.\n");
    printf("Expected: %d, received: %d\n", 2, actual);
    exit(-1);
  }
}

void assertNoVerticalAdjacentSimilarElements(
    Position visited[BOARD_SIZE * BOARD_SIZE],
    char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = 1, .col = 1};
  initializeVisitedPositions(p, visited);

  int actual = adjacentSimilarElements(0, VERTICAL, 'O', p, 1, visited, board);
  if (actual != 2) {
    printf("Assertion failed: no adjacent similar elements on vertical.\n");
    printf("Expected: %d, received: %d\n", 2, actual);
    exit(-1);
  }
}

void assertNoForwardDiagAdjacentSimilarElements(
    Position visited[BOARD_SIZE * BOARD_SIZE],
    char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = 2, .col = 0};
  initializeVisitedPositions(p, visited);

  int actual =
      adjacentSimilarElements(0, FORWARD_DIAG, 'X', p, 1, visited, board);
  if (actual != 2) {
    printf("Assertion failed: no adjacent similar elements on forward diag.\n");
    printf("Expected: %d, received: %d\n", 2, actual);
    exit(-1);
  }
}

void assertNoBackwardDiagAdjacentSimilarElements(
    Position visited[BOARD_SIZE * BOARD_SIZE],
    char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = 1, .col = 1};
  initializeVisitedPositions(p, visited);

  int actual =
      adjacentSimilarElements(0, BACKWARD_DIAG, 'O', p, 1, visited, board);
  if (actual != 2) {
    printf(
        "Assertion failed: no adjacent similar elements on backward diag.\n");
    printf("Expected: %d, received: %d\n", 2, actual);
    exit(-1);
  }
}

void assertSingleHorizontalAdjacentSimilarElement(
    Position visited[BOARD_SIZE * BOARD_SIZE],
    char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = 0, .col = 0};
  initializeVisitedPositions(p, visited);

  int actual =
      adjacentSimilarElements(0, HORIZONTAL, 'X', p, 1, visited, board);
  if (actual != 3) {
    printf("Assertion failed: no single adjacent similar element on "
           "horizontal.\n");
    printf("Expected: %d, received: %d\n", 3, actual);
    exit(-1);
  }
}

void assertSingleVerticalAdjacentSimilarElement(
    Position visited[BOARD_SIZE * BOARD_SIZE],
    char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = 1, .col = 0};
  initializeVisitedPositions(p, visited);

  int actual = adjacentSimilarElements(0, VERTICAL, 'X', p, 1, visited, board);
  if (actual != 3) {
    printf(
        "Assertion failed: no single adjacent similar element on vertical.\n");
    printf("Expected: %d, received: %d\n", 3, actual);
    exit(-1);
  }
}

void assertSingleForwardDiagAdjacentSimilarElement(
    Position visited[BOARD_SIZE * BOARD_SIZE],
    char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = 1, .col = 1};
  initializeVisitedPositions(p, visited);

  int actual =
      adjacentSimilarElements(0, FORWARD_DIAG, 'O', p, 1, visited, board);
  if (actual != 3) {
    printf("Assertion failed: no single adjacent similar element on forward "
           "diag.\n");
    printf("Expected: %d, received: %d\n", 3, actual);
    exit(-1);
  }
}

void assertSingleBackwardDiagAdjacentSimilarElement(
    Position visited[BOARD_SIZE * BOARD_SIZE],
    char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = 1, .col = 1};
  initializeVisitedPositions(p, visited);

  int actual =
      adjacentSimilarElements(0, BACKWARD_DIAG, 'O', p, 1, visited, board);
  if (actual != 3) {
    printf("Assertion failed: no single adjacent similar elements on backward "
           "diag.\n");
    printf("Expected: %d, received: %d\n", 3, actual);
    exit(-1);
  }
}

void assertDualHorizontalAdjacentSimilarElements(
    Position visited[BOARD_SIZE * BOARD_SIZE],
    char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = 1, .col = 2};
  initializeVisitedPositions(p, visited);

  int actual =
      adjacentSimilarElements(0, HORIZONTAL, 'X', p, 1, visited, board);
  if (actual != 4) {
    printf(
        "Assertion failed: no dual adjacent similar elements on horizontal.\n");
    printf("Expected: %d, received: %d\n", 4, actual);
    exit(-1);
  }
}

void assertDualVerticalAdjacentSimilarElements(
    Position visited[BOARD_SIZE * BOARD_SIZE],
    char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = 1, .col = 0};
  initializeVisitedPositions(p, visited);

  int actual = adjacentSimilarElements(0, VERTICAL, 'X', p, 1, visited, board);
  if (actual != 4) {
    printf(
        "Assertion failed: no dual adjacent similar elements on vertical.\n");
    printf("Expected: %d, received: %d\n", 4, actual);
    exit(-1);
  }
}

void assertDualForwardDiagAdjacentSimilarElements(
    Position visited[BOARD_SIZE * BOARD_SIZE],
    char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = 1, .col = 1};
  initializeVisitedPositions(p, visited);

  int actual =
      adjacentSimilarElements(0, FORWARD_DIAG, 'X', p, 1, visited, board);
  if (actual != 4) {
    printf("Assertion failed: no dual adjacent similar elements on forward "
           "diag.\n");
    printf("Expected: %d, received: %d\n", 4, actual);
    exit(-1);
  }
}

void assertDualBackwardDiagAdjacentSimilarElements(
    Position visited[BOARD_SIZE * BOARD_SIZE],
    char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = 2, .col = 2};
  initializeVisitedPositions(p, visited);

  int actual =
      adjacentSimilarElements(0, BACKWARD_DIAG, 'X', p, 1, visited, board);
  if (actual != 4) {
    printf("Assertion failed: no dual adjacent similar elements on backward "
           "diag.\n");
    printf("Expected: %d, received: %d\n", 4, actual);
    exit(-1);
  }
}

void assertNoWinnerSingleMatch(char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = 1, .col = 1};

  _Bool actual = validateWinner(p, 'O', board);
  if (actual != 0) {
    printf("Assertion failed: validate winner on no single match.\n");
    printf("Expected: %d, received: %d; for { row = %d, col = %d }\n", 0,
           actual, p.row, p.col);
    exit(-1);
  }
}

void assertNoWinnerDualMatch(char board[BOARD_SIZE][BOARD_SIZE]) {
  Position p = {.row = 0, .col = 0};

  _Bool actual = validateWinner(p, 'X', board);
  if (actual != 0) {
    printf("Assertion failed: validate winner on no dual match.\n");
    printf("Expected: %d, received: %d; for { row = %d, col = %d }\n", 0,
           actual, p.row, p.col);
    exit(-1);
  }
}

void assertWinnerHorizontal() {
  char board[BOARD_SIZE][BOARD_SIZE] = {
      {'O', 'O', 'O'}, {'X', 'O', 'X'}, {'7', 'X', '9'}};
  Position p = {.row = 0, .col = 0};

  _Bool actual = validateWinner(p, 'O', board);
  if (actual != 1) {
    printf("Assertion failed: validate winner on horizontal match.\n");
    printf("Expected: %d, received: %d; for { row = %d, col = %d }\n", 1,
           actual, p.row, p.col);
    exit(-1);
  }
}

void assertWinnerVertical() {
  char board[BOARD_SIZE][BOARD_SIZE] = {
      {'O', 'X', '3'}, {'O', '5', 'X'}, {'O', '8', '9'}};
  Position p = {.row = 1, .col = 0};

  _Bool actual = validateWinner(p, 'O', board);
  if (actual != 1) {
    printf("Assertion failed: validate winner on vertical match.\n");
    printf("Expected: %d, received: %d; for { row = %d, col = %d }\n", 1,
           actual, p.row, p.col);
    exit(-1);
  }
}

void assertWinnerForwardDiag() {
  char board[BOARD_SIZE][BOARD_SIZE] = {
      {'X', 'X', 'O'}, {'4', 'O', 'X'}, {'O', '8', '9'}};
  Position p = {.row = 1, .col = 1};

  _Bool actual = validateWinner(p, 'O', board);
  if (actual != 1) {
    printf("Assertion failed: validate winner on forward diag match.\n");
    printf("Expected: %d, received: %d; for { row = %d, col = %d }\n", 1,
           actual, p.row, p.col);
    exit(-1);
  }
}

void assertWinnerBackwardDiag() {
  char board[BOARD_SIZE][BOARD_SIZE] = {
      {'O', 'X', 'O'}, {'X', 'O', '6'}, {'X', '8', 'O'}};
  Position p = {.row = 2, .col = 2};

  _Bool actual = validateWinner(p, 'O', board);
  if (actual != 1) {
    printf("Assertion failed: validate winner on backward diag match.\n");
    printf("Expected: %d, received: %d; for { row = %d, col = %d }\n", 1,
           actual, p.row, p.col);
    exit(-1);
  }
}
