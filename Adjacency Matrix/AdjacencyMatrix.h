#ifndef _ADJACENCY_MATRIX
#define _ADJACENCY_MATRIX

#include <iostream>
using namespace std;

int const MAX_VERT = 6;
int const INFINITY = 1000; //Will represent "infinity" for our matrix

class AdjacencyMatrix
{
    private:
        //This matrix will store all the weights for each vertices
        int adjMat[MAX_VERT][MAX_VERT];

    public:
        AdjacencyMatrix();

        int getWeight(int row, int column)
        {return adjMat[row][column];};
};

#endif