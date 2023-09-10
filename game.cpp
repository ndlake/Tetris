#include "game.hpp"

// Return a random int between pA and pB
int game::GetRand(int pA, int pB)
{
    return rand() % (pB - pA + 1) + pA;
}

// Initializes game: selects first + second piece at random.
void game::initGame()
{
    srand(static_cast<int>(time(NULL)));

    // generate first piece
    mPiece = GetRand(0, 6);
    mRotation = GetRand(0, 3);
    mPosX = (BOARD_WIDTH / 2) + mPieces->getXSpawnPosition(mPiece, mRotation);
    mPosY = mPieces->getYSpawnPosition(mPiece, mRotation);

    // generate second piece
    mNextPiece = GetRand(0, 6);
    mNextRotation = GetRand(0, 3);
    mNextPosX = BOARD_WIDTH + 5;
    mNextPosY = 5;
}

void game::createNewPiece()
{
    // set next piece as current piece
    mPiece = mNextPiece;
    mRotation = mNextRotation;
    mPosX = BOARD_WIDTH / 2 + mPieces->getXSpawnPosition(mPiece, mRotation);
    mPosY = mPieces->getYSpawnPosition(mPiece, mRotation);

    // generate second piece
    mNextPiece = GetRand(0, 6);
    mNextRotation = GetRand(0, 3);
}

void game::DrawPiece(int pX, int pY, int pPiece, int pRotation)
{
    color mColor;

    int mPixelsX = mBoard->getXPixelPosition(pX);
    int mPixelsY = mBoard->getYPixelPosition(pY);
    for (int i = 0; i < PIECES_BLOCKS; i++)
    {
        for (int j = 0; j < PIECES_BLOCKS; j++)
        {
            switch (mPieces->getElementType(pPiece, pRotation, j, i))
            {
            case 1:
                mColor = GREEN;
                break;
            case 2:
                mColor = BLUE;
            }
            if (mPieces->getElementType(pPiece, pRotation, j, i) != 0)
            {
                mIO->drawRectangle(mPixelsX + i * BLOCK_SIZE, mPixelsY + j * BLOCK_SIZE, (mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1, (mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1, mColor);
            }
        }
    }
}

void game::DrawBoard()
{
    int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
    int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
    int mY = mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

    mIO->drawRectangle(mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, BLUE);
    mIO->drawRectangle(mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, BLUE);

    mX1 += 1;
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_WIDTH, j++)
        {
            if (!mBoard->isBlockFree(i, j))
            {
                mIO->drawRectangle(mX1 + i * BLOCK_SIZE - 1, mY + j * BLOCK_SIZE + BLOCK_SIZE - 1, RED);
            }
        }
    }
}

void game::drawScene()
{
    DrawBoard();
    DrawPiece(mPosX, mPosY, mRotation);
    DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation);
}
