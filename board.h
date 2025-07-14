#ifndef BOARD_H
#define BOARD_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include "cell.h"
#define numberOfNeighbours 8

class board{
    private: 
        cell **board;
        int size;
        int nbActiveCellsAtStart;
        
    public: 
        void init(int size, int nbActiveCellsAtStart);
        void populateNeighboursCells();
        void checkNeighboursIndex(int *x, int *y);
        void print();
        void update();


};




#endif


