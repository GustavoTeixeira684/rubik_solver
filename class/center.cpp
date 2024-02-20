#include "center.hpp"

Center::Center(short int color){

    this->piece = new Piece*[9];
    if(color == 4 || color == 5){
        for(int i = 0; i < 9; i++){
            if(i != 4){
                this->piece[i] = new Piece((i%2));
            }else{
                this->piece[4] = nullptr;
            }
        
        }   
    }else{
        this->piece[3] = new Piece(1);
        this->piece[4] = nullptr;
    }
    
    this->color = color;

}



Center::~Center(){
    this->piece = nullptr;
}