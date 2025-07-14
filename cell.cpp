#include "cell.h"


bool cell::getIsActive(){
    return this->isActive;
}

int cell::getnbActiveNeighbours(){
    return this->nbActiveNeighbours;
}

void cell::setIsActive(bool isActive){
    this->isActive = isActive;
}

void cell::setNeighbours(int index, cell* neighbour){
    this->neighbours[index] = neighbour;
}


void cell::updateState(){
    if(isActive) {
        tempIsActive = (nbActiveNeighbours == 2 || nbActiveNeighbours == 3);
    } else {
        tempIsActive = (nbActiveNeighbours == 3);
    }
}
void cell::computeNumberOfActiveNeighbours(){
    this->nbActiveNeighbours = 0;
    for(int i=0;i<numberOfNeighbours ;i++){
        if(this->neighbours[i]->getIsActive()){
            this->nbActiveNeighbours++;
        }
    }
}

void cell::applyChange(){
    this->isActive = this->tempIsActive;
}