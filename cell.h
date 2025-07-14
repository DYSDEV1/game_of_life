#ifndef CELL_H
#define CELL_H
#include <stdbool.h>
#include <stdio.h>
#define numberOfNeighbours 8

class cell{
    private: 
        bool isActive = false; 
        bool tempIsActive;
        int nbActiveNeighbours = 0;
        cell *neighbours[8]; 

    public: 
        //getters
        bool getIsActive();
        int getnbActiveNeighbours();

        //setters 
        void setIsActive(bool isActive);
        void setNeighbours(int index, cell* neighbour);

        void computeNumberOfActiveNeighbours();
        void updateState();
        void applyChange();
        
};




#endif