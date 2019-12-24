#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix()
{
    //Row 0
    adjMat[0][0] = 0;
    adjMat[0][1] = 120;
    adjMat[0][2] = 150;
    adjMat[0][3] = INFINITY;
    adjMat[0][4] = INFINITY;
    adjMat[0][5] = 500;

    //Row 1
    adjMat[1][0] = 120;
    adjMat[1][1] = 0;
    adjMat[1][2] = INFINITY;
    adjMat[1][3] = 75;
    adjMat[1][4] = INFINITY;
    adjMat[1][5] = 350;

    //Row 2
    adjMat[2][0] = 150;
    adjMat[2][1] = INFINITY;
    adjMat[2][2] = 0;
    adjMat[2][3] = INFINITY;
    adjMat[2][4] = 250;
    adjMat[2][5] = INFINITY;

    //Row 3
    adjMat[3][0] = INFINITY;
    adjMat[3][1] = 75;
    adjMat[3][2] = INFINITY;
    adjMat[3][3] = 0;
    adjMat[3][4] = 150;
    adjMat[3][5] = INFINITY;

    //Row 4
    adjMat[4][0] = INFINITY;
    adjMat[4][1] = INFINITY;
    adjMat[4][2] = 250;
    adjMat[4][3] = 150;
    adjMat[4][4] = 0;
    adjMat[4][5] = INFINITY;

    //Row 5
    adjMat[5][0] = 500;
    adjMat[5][1] = 350;
    adjMat[5][2] = INFINITY;
    adjMat[5][3] = INFINITY;
    adjMat[5][4] = INFINITY;
    adjMat[5][5] = 0;
}