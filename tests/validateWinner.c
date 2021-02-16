#include "../board.h"
#include "validateWinner-tester.h"

void testInitializeVisitedPositions() {
  for (int i = 0; i < BOARD_SIZE; i += 2) {
    for (int j = BOARD_SIZE - 1; j >= 0; j -= 2) {
      Position p = {.row = i, .col = j};
      assertInitializeVisitedPositions(p);
    }
  }
}

void testNoAdjacentSimilarElements() {
  Position visited[BOARD_SIZE * BOARD_SIZE];
  char board[BOARD_SIZE][BOARD_SIZE] = {
      {'X', '2', '3'}, {'4', 'O', '6'}, {'X', '8', '9'}};

  assertNoHorizontalAdjacentSimilarElements(visited, board);
  assertNoVerticalAdjacentSimilarElements(visited, board);
  assertNoForwardDiagAdjacentSimilarElements(visited, board);
  assertNoBackwardDiagAdjacentSimilarElements(visited, board);
}

void testSingleAdjacentSimilarElement() {
  Position visited[BOARD_SIZE * BOARD_SIZE];
  char board[BOARD_SIZE][BOARD_SIZE] = {
      {'X', 'X', '3'}, {'X', 'O', '6'}, {'O', '8', 'O'}};

  assertSingleHorizontalAdjacentSimilarElement(visited, board);
  assertSingleVerticalAdjacentSimilarElement(visited, board);
  assertSingleForwardDiagAdjacentSimilarElement(visited, board);
  assertSingleBackwardDiagAdjacentSimilarElement(visited, board);
}

void testDualAdjacentSimilarElements() {
  Position visited[BOARD_SIZE * BOARD_SIZE];
  char board[BOARD_SIZE][BOARD_SIZE] = {
      {'X', 'X', 'X'}, {'X', 'X', '6'}, {'X', '8', 'X'}};

  assertDualHorizontalAdjacentSimilarElements(visited, board);
  assertDualVerticalAdjacentSimilarElements(visited, board);
  assertDualForwardDiagAdjacentSimilarElements(visited, board);
  assertDualBackwardDiagAdjacentSimilarElements(visited, board);
}

void testNoWinner() {
  char board[BOARD_SIZE][BOARD_SIZE] = {
      {'X', '2', '3'}, {'X', 'O', '6'}, {'7', '8', '9'}};

  assertNoWinnerSingleMatch(board);
  assertNoWinnerDualMatch(board);
}

void testWinner() {
  assertWinnerHorizontal();
  assertWinnerVertical();
  assertWinnerForwardDiag();
  assertWinnerBackwardDiag();
}

void testValidateWinner() {
  testInitializeVisitedPositions();
  testNoAdjacentSimilarElements();
  testSingleAdjacentSimilarElement();
  testNoWinner();
  testWinner();
}
