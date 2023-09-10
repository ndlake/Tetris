#ifndef _GAME_
#define _GAME_

#include "board.hpp"
#include "pieces.hpp"
#include "IO.hpp"
#include <time.h>
#include <cstdlib>

#define WAIT_TIME 700 // time before a piece moves a single block

class game
{
public:
    game(board *pBoard, pieces *pPieces, IO *pIO, int pScreenHeight);

    void drawScene();
    void createNewPiece();

    int mPosX, mPosY;      // position of currently moving piece
    int mPiece, mRotation; // type of piece and current rotation

private:
    int mScreenHeight;
    int mNextPosX, mNextPosY;      // position of next piece
    int mNextPiece, mNextRotation; // type and rotation of next piece

    board *mBoard;
    pieces *mPieces;
    IO *mIO;

    int GetRand(int pA, int pB);
    void initGame();
    void DrawPiece(int pX, int pY, int pPiece, int pRotation);
    void DrawBoard();
};
#endif