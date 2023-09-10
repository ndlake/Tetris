#include "board.hpp"

bool board::isGameOver()
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        if (boardData[i][0])
        {
            return true;
        }
    }
    return false;
}

void board::storePiece(int posX, int posY, int pieceType, int pieceRotation)
{
    for (int i = posX, i2 = 0; i < posX + PIECE_BLOCKS; i++, i2++)
    {
        for (int j = posY, j2 = 0; j < posY + PIECE_BLOCKS; j++, j2++)
        {
            if (currentPieces->getElementType(pieceType, pieceRotation, i2, j2))
            {
                boardData[i][j] = 1;
            }
        }
    }
}

bool board::isMovePossible(int pieceX, int pieceY, int pieceType, int pieceRotation)
{
    for (int i = pieceX, i2; i < pieceX + PIECE_BLOCKS; i++, i2++)
    {
        for (int j = pieceY, j2; j < pieceY + PIECE_BLOCKS; j++, j2++)
        {
            if (currentPieces->getElementType(pieceType, pieceRotation, pieceX, pieceY))
            {
                // check if inbounds or if element is already occupied
                if (i >= BOARD_WIDTH || i < 0 || j >= BOARD_HEIGHT || !isBlockFree(i2, j2))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool board::isBlockFree(int pieceX, int pieceY)
{
    return (boardData[pieceX][pieceY] == 0);
}

void board::initBoard()
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {
            boardData[i][j] = 0;
        }
    }
}

void board::deleteLines()
{
    for (int j = 0; j < BOARD_HEIGHT; j++)
    {
        int i = 0;
        while (i < BOARD_WIDTH)
        {
            if (!boardData[i][j])
            {
                break;
            }
            i++;
        }
        if (i >= BOARD_WIDTH)
        {
            deleteLine(j);
        }
    }
    return;
}

void board::deleteLine(int Y)
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        boardData[i][Y] = 0;
    }
    for (int j = Y; j > 0; j--)
    {
        for (int i = 0; i < BOARD_WIDTH; i++)
        {
            boardData[i][j] = boardData[i][j - 1];
        }
    }
}

// Position of block in board in X
int board::getXPixelPosition(int xPos)
{
    return (BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) + (xPos * BLOCK_SIZE));
}

// Position of block in board in Y
int board::getYPixelPosition(int yPos)
{
    return (screenHeight - (BLOCK_SIZE * (BOARD_HEIGHT / 2)) + (yPos * BLOCK_SIZE));
}