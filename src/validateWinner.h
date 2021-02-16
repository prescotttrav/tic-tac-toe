#ifndef HEADER_VALIDATE_WINNER
#define HEADER_VALIDATE_WINNER

#include "board.h"
#include "position.h"

enum Direction
{
  HORIZONTAL,
  VERTICAL,
  FORWARD_DIAG,
  BACKWARD_DIAG
};

_Bool validateWinner(Position p, char symbol,
                     char board[BOARD_SIZE][BOARD_SIZE]);

void initializeVisitedPositions(Position p, Position visited[]);

int adjacentSimilarElements(int count, enum Direction dir, char symbol,
                            Position p, int index, Position visited[],
                            char board[BOARD_SIZE][BOARD_SIZE]);

#endif
