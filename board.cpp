#include "board.h"



void board::init(int size, int nbActiveCellsAtStart){

    this->size = size;

    this->nbActiveCellsAtStart = nbActiveCellsAtStart;

    srand(time(0));

    cell **newBoard = (cell**)malloc(sizeof(cell*)*size);

    for(int i=0; i<size;i++){
        newBoard[i] = (cell*)malloc(sizeof(cell)*size);
    }
    
    this->board = newBoard;

    //random
    
    for(int i=0; i< nbActiveCellsAtStart; i++){
        int randX = rand() % size; 
        int randY = rand() % size;
        this->board[randX][randY].setIsActive(true);

    }



    //glider 
    /* 
    board[1][2].setIsActive(true);
    board[2][3].setIsActive(true);
    board[3][1].setIsActive(true);
    board[3][2].setIsActive(true);
    board[3][3].setIsActive(true);
    */

    //blinker 
    /*
    board[4][6].setIsActive(true);
    board[5][6].setIsActive(true);
    board[6][6].setIsActive(true);
    */

    //toad 
    /*
    board[5][5].setIsActive(true);
    board[5][6].setIsActive(true);
    board[5][7].setIsActive(true);
    board[6][4].setIsActive(true);
    board[6][5].setIsActive(true);
    board[6][6].setIsActive(true);
    */

    //beacon 
    /*
    board[4][4].setIsActive(true);
    board[4][5].setIsActive(true);
    board[5][4].setIsActive(true);
    board[5][5].setIsActive(true);

    board[6][6].setIsActive(true);
    board[6][7].setIsActive(true);
    board[7][6].setIsActive(true);
    board[7][7].setIsActive(true);
    
    */

    //LWSS
    /*
    board[5][5].setIsActive(true);
    board[5][6].setIsActive(true);
    board[6][4].setIsActive(true);
    board[6][5].setIsActive(true);
    board[6][6].setIsActive(true);
    board[6][7].setIsActive(true);
    board[7][4].setIsActive(true);
    board[7][7].setIsActive(true);
    board[8][5].setIsActive(true);
    board[8][6].setIsActive(true);
    */


}


 void board::checkNeighboursIndex(int *x, int *y){
    if(*x < 0){
        *x = size-1;
    }
    if(*x >= size){
        *x = 0;
    }
    if(*y < 0){
        *y = size-1;
    }
    if(*y >= size){
        *y = 0;
    }
 }

void board::populateNeighboursCells(){

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            int x = i;
            int y = j;
            int dx[] = {-1,-1,-1,0,0,1,1,1};
            int dy[] = {-1,0,1,-1,1,-1,0,1};
            for(int k=0;k<numberOfNeighbours; k++){
                int tempX = x + dx[k];
                int tempY = y + dy[k];
                checkNeighboursIndex(&tempX,&tempY);
                //printf("%d, %d, %p\n",tempX, tempY, &board[tempX][tempY]);
                board[i][j].setNeighbours(k,&board[tempX][tempY]);
            }
           
        }
    }
}


void board::print(){

    for(int i = 0; i<size;i++){
        for(int j = 0; j<size;j++){
            if(board[i][j].getIsActive()){
                printf("0 ");
            }else{
                printf(". ");
            }
        }
        printf("\n");
    }
}

void board::update(){
    for(int i = 0;i<size;i++){
        for(int j= 0; j<size;j++){
            board[i][j].computeNumberOfActiveNeighbours();
            board[i][j].updateState();
        } 
    }
    for(int i = 0;i<size;i++){
        for(int j= 0; j<size;j++){
            board[i][j].applyChange();
        }
    }
}