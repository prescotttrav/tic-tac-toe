## Tic Tac Toe - Console Game [![CircleCI](https://circleci.com/gh/circleci/circleci-docs.svg?style=shield)](https://circleci.com/gh/prescotttrav/tic-tac-toe)

You versus your system, the grand prix of child games!

### Building Tic Tac Toe

It is as simple as:

```
% make tictactoe
```

### Running Tic Tac Toe

Once built, run:

```
% ./tictactoe
```

### Source code layout

The tic tac toe root directory only contains this README, the Makefile, circleci config and clang formatter.

Inside the root are the following important directories:

- `src`: contains tic tac toe implementation, written in C.
- `tests`: contains unit tests, implemented in C.

#### main.c

This is the entry point of the tic tac toe game.

Within the `main()` defined function, the game is initialized and then looped between players until a win, or draw occurs.

#### playerMove.c

This file defines the player movement & turn functions. Including both user & system movements, which comprise of a single turn when a valid target movement is selected.

A valid target movement is defined as a position that is within the board bounds & not currently occupied by an element.

#### validateWinner.c

This file defines the recursive graph traversal algorithm determining a tic tac toe winner. 

The algorithm begins with the user's last placed element & attempts to match similar elements horizontally, vertically, and both diagonal directions. The recursive base case terminates if the given position is out of the board's range or if the given position's element does not match the root element.

The algorithm runs bi-direcitonal for position agnostics.

#### position.c

This file contains all position functions, including:

- Converting console display value to position.
- Traversing position on the board.
- Asserting equality between two positions.
- Asserting occupied position.

#### board.c

This file defines board specific functions, including:

- Placing an element on the board.
- Initializing game board.
- Assert display value & position is within board bounds.

#### board.h

This header defines the size of the game board. The default is set to:

```c
#define BOARD_SIZE 3
```

However, any board size can be defined; based purely on your heart's intent to increase the difficulty in challenging your system.

#### display.c

This file contains the visual console content, such as:

- Building the game board.
- Game title & results.
- Defining which player's turn it is.

#### tests

Testing is strictly forced in this repo & Circle CI is configured to both compile & run unit tests. Please update or add any tests if any features or functions are added or updated.

