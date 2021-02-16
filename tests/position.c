#include "../src/board.h"
#include "position-tester.h"

void testPositionEquality() {
  int i, j;
  for (i = 0, j = 3; i < 3; ++i, --j) {
    assertPositionEquality(i, j);
    assertPositionInequality(i, j);
  }
}

void testEmptyPosition() {
  assertPositionIsEmpty();
  assertPositionIsNotEmpty();
}

void testConvertDisplayValueToPosition() {
  for (int i = 1; i <= BOARD_SIZE * BOARD_SIZE; ++i) {
    assertConvertDisplayValueToPosition(i);
  }
}

void testOccupiedDisplayValue() {
  char board[BOARD_SIZE][BOARD_SIZE];
  initializeScatteredBoard(board);

  assertOccupiedDisplayValue(ODD, board);
  assertOccupiedDisplayValue(EVEN, board);
}

void testVisitedPosition() {
  assertVisitedPositionOnNoPriorVisits();
  assertVisitedPositionOnNoMatch();
  assertVisitedPositionOnMatch();
}

void testAdvancePosition() {
  for (int i = HORIZONTAL; i <= BACKWARD_DIAG; ++i) {
    assertAdvancePosition(i);
  }
}

void testRetractPosition() {
  for (int i = HORIZONTAL; i <= BACKWARD_DIAG; ++i) {
    assertRetractPosition(i);
  }
}

void testPositionUtils() {
  testPositionEquality();
  testEmptyPosition();
  testConvertDisplayValueToPosition();
  testOccupiedDisplayValue();
  testVisitedPosition();
  testAdvancePosition();
  testRetractPosition();
}
