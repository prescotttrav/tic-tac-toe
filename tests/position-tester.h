#pragma once

#include "../src/board.h"
#include "../src/position.h"
#include <stdio.h>
#include <stdlib.h>

enum Values
{
  ODD,
  EVEN
};

void assertPositionEquality(int i, int j) {
  Position p1 = {.row = i, .col = j};
  Position p2 = {.row = i, .col = j};
  _Bool actual = positionEquality(p1, p2);

  if (actual != 1) {
    printf("Assertion failed: Position equality.\n");
    printf("Expected: %d, actual: %d; for p1: { row = %d, col = %d } and p2: { "
           "row = %d, col = %d }\n",
           1, actual, p1.row, p1.col, p2.row, p2.col);
    exit(-1);
  }
}

void assertPositionInequality(int i, int j) {
  Position p1 = {.row = i, .col = j};
  Position p2 = {.row = j, .col = i};
  _Bool actual = positionEquality(p1, p2);

  if (actual != 0) {
    printf("Assertion failed: Position inequality.\n");
    printf("Expected: %d, actual: %d; for p1: { row = %d, col = %d } and p2: { "
           "row = %d, col = %d }\n",
           0, actual, p1.row, p1.col, p2.row, p2.col);
    exit(-1);
  }
}

void assertPositionIsEmpty() {
  Position p = {.row = -1, .col = -1};
  _Bool actual = emptyPosition(p);
  if (actual != 1) {
    printf("Assertion failed: Position is empty.\n");
    printf("Expected: %d, received: %d; for Position: { row = %d, col = %d }\n",
           1, actual, p.row, p.col);
    exit(-1);
  }
}

void assertPositionIsNotEmpty() {
  Position p = {.row = 0, .col = 2};
  _Bool actual = emptyPosition(p);
  if (actual != 0) {
    printf("Assertion failed: Position is not empty.\n");
    printf("Expected: %d, received: %d; for Position: { row = %d, col = %d }\n",
           1, actual, p.row, p.col);
    exit(-1);
  }
}

int expectedRow(int displayVal) {
  switch (displayVal) {
    case 1:
    case 2:
    case 3:
      return 0;
    case 4:
    case 5:
    case 6:
      return 1;
    case 7:
    case 8:
    case 9:
    default:
      return 2;
  }
}

int expectedCol(int displayVal) {
  switch (displayVal) {
    case 1:
    case 4:
    case 7:
      return 0;
    case 2:
    case 5:
    case 8:
      return 1;
    case 3:
    case 6:
    case 9:
    default:
      return 2;
  }
}

void assertConvertDisplayValueToPosition(int displayVal) {
  Position actual, expected;
  if (BOARD_SIZE == 3) {
    expected.row = expectedRow(displayVal);
    expected.col = expectedCol(displayVal);
    actual = convertDisplayValueToPosition(displayVal);
    if (!positionEquality(actual, expected)) {
      printf("Assertion failed: convert display value to Position.\n");
      printf("Expected: { row = %d, col = %d }, received: { row = %d, col = %d "
             "}; for display value: %d\n",
             expected.row, expected.col, actual.row, actual.col, displayVal);
      exit(-1);
    }
  }
}

void initializeScatteredBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
  char boardContent[BOARD_SIZE][BOARD_SIZE] = {
      {'O', '2', 'X'}, {'4', 'O', '6'}, {'O', '8', 'X'}};
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      board[i][j] = boardContent[i][j];
    }
  }
}

void assertOccupiedDisplayValue(enum Values values,
                                char board[BOARD_SIZE][BOARD_SIZE]) {
  _Bool actual, expected;
  _Bool isOdd = values == ODD;
  for (int i = isOdd ? 1 : 2; i < BOARD_SIZE * BOARD_SIZE + 1; i += 2) {
    expected = isOdd ? 1 : 0;
    actual = occupiedDisplayValue(i, board);
    if (actual != expected) {
      printf("Assertion failed: occupied display value.\n");
      printf("Expected: %d, received: %d; for display value: %d\n",
             isOdd ? 1 : 0, actual, i);
      exit(-1);
    }
  }
}

void assertVisitedPositionOnNoPriorVisits() {
  Position cur = {.row = 2, .col = 1};
  Position visited[BOARD_SIZE] = {
      [0 ... BOARD_SIZE - 1] = {.row = -1, .col = -1}};

  _Bool actual = visitedPosition(cur, visited);
  if (actual != 0) {
    printf("Assertion failed: visited position.\n");
    printf("Expected: %d, received: %d; for { row = %d, col = %d }\n", 0,
           actual, cur.row, cur.col);
    exit(-1);
  }
}

void assertVisitedPositionOnNoMatch() {
  Position cur = {.row = 2, .col = 1};
  Position visited[3] = {[0] = {.row = 2, .col = 2},
                         [1] = {.row = 0, .col = 1},
                         [2] = {.row = 1, .col = 1}};

  _Bool actual = visitedPosition(cur, visited);
  if (actual != 0) {
    printf("Assertion failed: visited position.\n");
    printf("Expected: %d, received: %d; for { row = %d, col = %d }\n", 0,
           actual, cur.row, cur.col);
    exit(-1);
  }
}

void assertVisitedPositionOnMatch() {
  Position cur = {.row = 1, .col = 1};
  Position visited[3] = {[0] = {.row = 2, .col = 2},
                         [1] = {.row = 0, .col = 1},
                         [2] = {.row = 1, .col = 1}};

  _Bool actual = visitedPosition(cur, visited);
  if (actual != 1) {
    printf("Assertion failed: visited position.\n");
    printf("Expected: %d, received: %d; for { row = %d, col = %d }\n", 1,
           actual, cur.row, cur.col);
    exit(-1);
  }
}

char *directionToString(enum Direction dir) {
  switch (dir) {
    case 0:
      return "HORIZONTAL\0";
    case 1:
      return "VERTICAL\0";
    case 2:
      return "FORWARD_DIAG\0";
    case 3:
    default:
      return "BACKWARD_DIAG\0";
  }
}

Position expectedAdvancePosition(enum Direction dir, Position p) {
  switch (dir) {
    case 0:
      p.col = 2;
      break;
    case 1:
      p.row = 2;
      break;
    case 2:
      p.row = 0;
      p.col = 2;
      break;
    case 3:
    default:
      p.row = 2;
      p.col = 2;
      break;
  }
  return p;
}

void assertAdvancePosition(enum Direction dir) {
  Position actual = {.row = 1, .col = 1};
  Position expected = expectedAdvancePosition(dir, actual);

  actual = advancePosition(dir, actual);
  if (!positionEquality(actual, expected)) {
    printf("Assertion failed: advance position.\n");
    printf("Expected: { row = %d, col = %d }, received: { row = %d, col = %d "
           "}; for dir: %s\n",
           expected.row, expected.col, actual.row, actual.col,
           directionToString(dir));
    exit(-1);
  }
}

Position expectedRetractPosition(enum Direction dir, Position p) {
  switch (dir) {
    case 0:
      p.col = 0;
      break;
    case 1:
      p.row = 0;
      break;
    case 2:
      p.row = 2;
      p.col = 0;
      break;
    case 3:
    default:
      p.row = 0;
      p.col = 0;
      break;
  }
  return p;
}

void assertRetractPosition(enum Direction dir) {
  Position actual = {.row = 1, .col = 1};
  Position expected = expectedRetractPosition(dir, actual);

  actual = retractPosition(dir, actual);
  if (!positionEquality(actual, expected)) {
    printf("Assertion failed: retract position.\n");
    printf("Expected: { row = %d, col = %d }, received: { row = %d, col = %d "
           "}; for dir: %s\n",
           expected.row, expected.col, actual.row, actual.col,
           directionToString(dir));
    exit(-1);
  }
}
