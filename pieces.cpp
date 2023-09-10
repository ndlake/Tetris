
#include "pieces.hpp"

int pieces::getElementType(int pieceType, int pieceRotation, int pieceX, int pieceY)
{
    if (pieceType >= 7 || pieceRotation >= 4 || pieceX >= 5 || pieceY >= 5)
    {
        return 0;
    }
    return pieceData[pieceType][pieceRotation][pieceX][pieceY];
}

int pieces::getXSpawnPosition(int pieceType, int pieceRotation)
{
    if (pieceType >= 7 || pieceRotation >= 4)
    {
        return 0;
    }
    return initialDisplacement[pieceType][pieceRotation][0];
}

int pieces::getYSpawnPosition(int pieceType, int pieceRotation)
{
    if (pieceType >= 7 || pieceRotation >= 4)
    {
        return 0;
    }
    return initialDisplacement[pieceType][pieceRotation][1];
}