#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include "cell.h"
#include "board.h"



int main(void){

    board board;
    board.init(30,200);
    board.populateNeighboursCells();
    while(true){
        board.update();
        board.print();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        //std::this_thread::sleep_for(std::chrono::microseconds(5000));
        system("clear"); 
        
    }

    return 0; 
}