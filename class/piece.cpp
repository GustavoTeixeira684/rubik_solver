#include "piece.hpp"

Piece::Piece(bool type){

    this->type = type;
    if(type){ // Peça de meio
        
        this->color = new int[2];
        this->length = 2;
        this->center = new int[2];
    }else{
        this->color = new int[3];
        this->length = 3;
        this->center = new int[3];
    }

}

Piece::~Piece(){
    delete this->color;
}

void Piece::setColor(int index, int color){

    this->color[index] = color;
    this->center[index] = color;

}

void Piece::changeCenter(int color, int center){

    for(int i = 0; i < this->length; i++){
        if(this->color[i] == color){
            this->center[i] = center;
            break;
        }
    }

}

int Piece::getColor(int center){
    for(int i = 0; i < this->length; i++){
        if(this->center[i] == center){
            return this->color[i];
        }
    }
    return -1;

}

int *Piece::getOtherColor(int color){

    int *retorno = new int[(this->type == true ? 1 : 2)];

    for(int i = 0, contador = 0; i < this->length; i++){
        if(this->color[i] != color){
            retorno[contador] = this->color[i];
            contador++;
        }
    }
    return retorno;

}

int Piece::getCenter(int color){
    for(int i = 0; i < this->length; i++){
        if(this->color[i] == color){
            return this->center[i];
        }
    }
    return -1;
}

int *Piece::getOtherCenter(int center){
    int *retorno = new int[(this->type == true ? 1 : 2)];

    for(int i = 0, contador = 0; i < this->length; i++){
        if(this->center[i] != center){
            retorno[contador] = this->center[i];
            contador++;
        }
    }
    return retorno;
}