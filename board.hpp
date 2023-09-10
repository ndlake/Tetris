#ifndef _BOARD_
#define _BOARD_

// Includes
#include "pieces.hpp"

// Define
#define BOARD_LINE_WIDTH 6
#define BLOCK_SIZE 16
#define BOARD_POSITION 320
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define MIN_VERTICAL_MARGIN 20
#define MIN_HORIZONTAL_MARGIN 20
#define PIECE_BLOCKS 5

// board class
class board
{
    board(pieces *pieces, int screenHeight);

    int getXPixelPosition(int piecePosition);
    int getYPixelPosition(int piecePosition);
    bool isBlockFree(int pieceX, int pieceY);
    bool isMovePossible(int pieceX, int pieceY, int piece, int pieceRotation);
    void storePiece(int posX, int posY, int pieceType, int pieceRotation);
    void deleteLines();
    bool isGameOver();

private:
    int boardData[BOARD_WIDTH][BOARD_HEIGHT];
    pieces *currentPieces;
    int screenHeight;

    void initBoard();
    void deleteLine(int Y);
};
#endif
