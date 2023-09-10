#include "game.hpp"
#ifndef LINUX
#include <windows.h>
#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
    IO mIO;
    int mScreenHeight = mIO.getScreenHeight();

    pieces mPieces;

    board mBoard(&mPieces, mScreenHeight);

    game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);

    unsigned long mTime1 = SDL_GetTicks();

    while (!mIO.IsKeyDown(SDLK_ESCAPE))
    {
        mIO.clearScreen();
        mIO.updateScreen();

        int mKey = mIO.pollKey();

        switch (mKey)
        {
        case (SDLK_RIGHT):
            if (mBoard.isMovePossible(mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
            {
                mGame.mPosX++;
            }
            break;
        case (SDLK_LEFT):
            if (mBoard.isMovePossible(mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
            {
                mGame.mPosX--;
            }
            break;
        case (SDLK_DOWN):
            if (mBoard.isMovePossible(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
            {
                mGame.mPosY++;
            }
            break;
        case (SDLK_x):
            while (mBoard.IsMovePossible(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation))
            {
                mGame.mPosY++;
            }
            mBoard.storePiece(mGame.mPosX, mGame.mPosY - 1, mGame.mPiece, mGame.mRotation);
            mBoard.deleteLines();
            if (mBoard.isGameOver())
            {
                mIO.getKey();
                exit(0);
            }
            mGame.createNewPiece();
            break;
        case (SDLK_z):
            if (mBoard.isMovePossible(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4))
            {
                mGame.mRotation = (mGame.mRotation + 1) % 4;
            }
            break;
        }
        unsigned long mTime2 = SDL_GetTicks();
        if ((mTime2 - mTime1) > WAIT_TIME)
        {
            if (mBoard.IsMovePossible(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
            {
                mGame.mPosY++;
            }
            else
            {
                mBoard.storePiece(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);
                mBoard.deleteLines();

                if (mBoard.IsGameOver())
                {
                    mIO.getKey();
                    exit(0);
                }
            }
            mGame.createNewPiece();
            mTime1 = SDL_GetTicks();
        }
    }
    return 0;
}
