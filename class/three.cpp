#include "three.hpp"
#include <iostream>
#include <vector>


// Funções auxiliares
constexpr void print_space(bool type){ // false para init e true para final

    if(!type){
        std::cout << "   ";
    }
    for(int i = 0; i < 4; i++){
        std::cout << " ";
    }

    if(type){
        std::cout << std::endl;
    }

}



Three::Three(){

    int contador;
    Piece **aux = new Piece*[3];
    this->center = new Center*[6]; // Criando os seis lados

    // Populando o branco
    this->center[4] = new Center(4); // Criando o lado branco (Inicio pois a regra é diferente).

    this->center[4]->piece[0]->setColor(0, WHITE);
    this->center[4]->piece[0]->setColor(1, BLUE);
    this->center[4]->piece[0]->setColor(2, ORANGE);
    this->center[4]->piece[1]->setColor(0, WHITE);
    this->center[4]->piece[1]->setColor(1, BLUE);
    this->center[4]->piece[2]->setColor(0, WHITE);
    this->center[4]->piece[2]->setColor(1, BLUE);
    this->center[4]->piece[2]->setColor(2, RED);
    this->center[4]->piece[3]->setColor(0, WHITE);
    this->center[4]->piece[3]->setColor(1, ORANGE);
    this->center[4]->piece[5]->setColor(0, WHITE);
    this->center[4]->piece[5]->setColor(1, RED);
    this->center[4]->piece[6]->setColor(0, WHITE);
    this->center[4]->piece[6]->setColor(1, GREEN);
    this->center[4]->piece[6]->setColor(2, ORANGE);
    this->center[4]->piece[7]->setColor(0, WHITE);
    this->center[4]->piece[7]->setColor(1, GREEN);
    this->center[4]->piece[8]->setColor(0, WHITE);
    this->center[4]->piece[8]->setColor(1, GREEN);
    this->center[4]->piece[8]->setColor(2, RED);
    
    // Populando Amarelo
    this->center[5] = new Center(5);
    this->center[5]->piece[0]->setColor(0, YELLOW);
    this->center[5]->piece[0]->setColor(1, GREEN);
    this->center[5]->piece[0]->setColor(2, ORANGE);
    this->center[5]->piece[1]->setColor(0, YELLOW);
    this->center[5]->piece[1]->setColor(1, GREEN);
    this->center[5]->piece[2]->setColor(0, YELLOW);
    this->center[5]->piece[2]->setColor(1, GREEN);
    this->center[5]->piece[2]->setColor(2, RED);
    this->center[5]->piece[3]->setColor(0, YELLOW);
    this->center[5]->piece[3]->setColor(1, ORANGE);
    this->center[5]->piece[5]->setColor(0, YELLOW);
    this->center[5]->piece[5]->setColor(1, RED);
    this->center[5]->piece[6]->setColor(0, YELLOW);
    this->center[5]->piece[6]->setColor(1, BLUE);
    this->center[5]->piece[6]->setColor(2, ORANGE);
    this->center[5]->piece[7]->setColor(0, YELLOW);
    this->center[5]->piece[7]->setColor(1, BLUE);
    this->center[5]->piece[8]->setColor(0, YELLOW);
    this->center[5]->piece[8]->setColor(1, BLUE);
    this->center[5]->piece[8]->setColor(2, RED);


    
    this->center[4]->piece[4] = nullptr;
    
    // Populando azul, vermelho, verde e laranja
    for(int i = 0; i < 4; i++){
        
        this->center[i] = new Center(i);
        this->center[i]->piece[3]->setColor(0, i);
        this->center[i]->piece[3]->setColor(1, (i + 3) % 4);
        // this->center[i]->piece[5]->setColor(0, i);
        // this->center[i]->piece[5]->setColor(1, (i + 1 % 4));
 
        for(int j = 0, contador = 0; j < 9; j++){
            if(j != 4){
                if(this->center[YELLOW]->piece[j]->getColor(i) != -1){
                    aux[contador] = this->center[YELLOW]->piece[j];
                    contador++;
                }
            }
        }

        for(int j = 0, contador = 0; j < 3; j++, contador++){

            if(aux[contador]->type == false){
                if(aux[contador]->getColor((i+3)%4) == -1){
                    this->center[i]->piece[2] = aux[contador];
                }else{
                    this->center[i]->piece[0] = aux[contador];
                }
            }else{
                this->center[i]->piece[1] = aux[contador];
            }
        }

        for(int j = 0, contador = 0; j < 9; j++){
            if(j != 4){
                if(this->center[WHITE]->piece[j]->getColor(i) != -1){
                    aux[contador] = this->center[WHITE]->piece[j];
                    contador++;
                }
            }
        }

        for(int j = 6, contador = 0; j < 9; j++, contador++){
            
            if(!aux[contador]->type){
                if(aux[contador]->getColor((i+3)%4) == -1){
                    this->center[i]->piece[8] = aux[contador];
                }else{
                    this->center[i]->piece[6] = aux[contador];
                }
            }else{
                this->center[i]->piece[7] = aux[contador];
            }

        }
        

    }
    this->center[ORANGE]->piece[5] = this->center[BLUE]->piece[3];
    this->center[BLUE]->piece[5] = this->center[RED]->piece[3];
    this->center[RED]->piece[5] = this->center[GREEN]->piece[3];
    this->center[GREEN]->piece[5] = this->center[ORANGE]->piece[3];
    aux = nullptr;
    

}

void Three::changeCenter(Center *current_center, Piece *new_piece, int index, int color){

    current_center->piece[index] = new_piece;
    
    new_piece->changeCenter(color, current_center->color);

}

void Three::right(){

    Piece **temp = new Piece*[3];
    int color_temp[2];
    temp[0] = this->center[BLUE]->piece[2];
    temp[1] = this->center[BLUE]->piece[5];
    temp[2] = this->center[BLUE]->piece[8];
    // Capturando as cores de peças que sofrem de atraso na atualização da cor
    // Esse ponto faz com que, quanto formos atualizar a cor de duas das peças (a cada movimento),
    // As mesmas ja estejam apontando para os centros novos. Usamos o vetor de controle para não perder a referência

    color_temp[0] = temp[2]->getColor(BLUE);
    color_temp[1] = this->center[GREEN]->piece[6]->getColor(GREEN);

    for(int i = 2; i >= 0; i--){
        
        this->changeCenter(this->center[BLUE], this->center[WHITE]->piece[(2+3*i)], (2+3*i), this->center[WHITE]->piece[(2+3*i)]->getColor(WHITE));
        this->changeCenter(this->center[WHITE], this->center[GREEN]->piece[(6-3*i)], (2+3*i), this->center[GREEN]->piece[(6-3*i)]->getColor(GREEN));
        this->changeCenter(this->center[GREEN], this->center[YELLOW]->piece[(2+3*i)], (6-3*i), this->center[YELLOW]->piece[(2+3*i)]->getColor(YELLOW));
        this->changeCenter (this->center[YELLOW], temp[i], (2+3*i), temp[i]->getColor(BLUE));

    }
    temp[0] = this->center[RED]->piece[0];
    temp[1] = this->center[RED]->piece[1];
    temp[2] = this->center[RED]->piece[2];

    this->center[RED]->piece[0] = this->center[RED]->piece[6];
    this->center[RED]->piece[1] = this->center[RED]->piece[3];
    this->center[RED]->piece[2] = temp[0];
    this->center[RED]->piece[3] = this->center[RED]->piece[7];
    this->center[RED]->piece[7] = this->center[RED]->piece[5];
    this->center[RED]->piece[5] = temp[1];
    this->center[RED]->piece[6] = this->center[RED]->piece[8];
    this->center[RED]->piece[8] = temp[2];

    temp = nullptr;

}

void Three::right_line(){

    Piece **temp = new Piece*[3];
    int color_temp;
    temp[0] = this->center[GREEN]->piece[6];
    temp[1] = this->center[GREEN]->piece[3];
    temp[2] = this->center[GREEN]->piece[0];
    // Capturando as cores de peças que sofrem de atraso na atualização da cor
    // Esse ponto faz com que, quanto formos atualizar a cor de duas das peças (a cada movimento),
    // As mesmas ja estejam apontando para os centros novos. Usamos o vetor de controle para não perder a referência

    color_temp = temp[0]->getColor(GREEN);

    for(int i = 0; i < 3; i++){

        this->changeCenter(this->center[GREEN], this->center[WHITE]->piece[(2+3*i)], (6-3*i), this->center[WHITE]->piece[(2+3*i)]->getColor(WHITE));
        this->changeCenter(this->center[WHITE], this->center[BLUE]->piece[(2+3*i)], (2+3*i), this->center[BLUE]->piece[(2+3*i)]->getColor(BLUE));
        this->changeCenter(this->center[BLUE], this->center[YELLOW]->piece[(2+3*i)], (2+3*i),this->center[YELLOW]->piece[(2+3*i)]->getColor(YELLOW));
        // this->changeCenter(this->center[WHITE], this->center[BLUE]->piece[(2+3*i)], (2+3*i), (i == 2 ? color_temp[1] : this->center[BLUE]->piece[(2+3*i)]->getColor(BLUE)));
        

    }
    
    this->changeCenter(this->center[YELLOW], temp[0], 2, color_temp);
    this->changeCenter(this->center[YELLOW], temp[1], 5, temp[1]->getColor(GREEN));
    this->changeCenter(this->center[YELLOW], temp[2], 8, temp[2]->getColor(GREEN));

    temp[0] = this->center[RED]->piece[0];
    temp[1] = this->center[RED]->piece[1];

    this->center[RED]->piece[0] = this->center[RED]->piece[2];
    this->center[RED]->piece[1] = this->center[RED]->piece[5];
    this->center[RED]->piece[2] = this->center[RED]->piece[8];
    this->center[RED]->piece[5] = this->center[RED]->piece[7];
    this->center[RED]->piece[7] = this->center[RED]->piece[3];
    this->center[RED]->piece[3] = temp[1];
    this->center[RED]->piece[8] = this->center[RED]->piece[6];
    this->center[RED]->piece[6] = temp[0];

    temp = nullptr;

}

void Three::right_two(){

    Piece **temp1 = new Piece*[3];
    Piece **temp2 = new Piece*[3];

    temp1[0] = this->center[BLUE]->piece[2];
    temp1[1] = this->center[BLUE]->piece[5];
    temp1[2] = this->center[BLUE]->piece[8];

    temp2[0] = this->center[WHITE]->piece[2];
    temp2[1] = this->center[WHITE]->piece[5];
    temp2[2] = this->center[WHITE]->piece[8];

    for(int i = 0; i < 3; i++){

        this->changeCenter(this->center[BLUE], this->center[GREEN]->piece[(6-3*i)], (2+3*i), this->center[GREEN]->piece[(6-3*i)]->getColor(GREEN));
        this->changeCenter(this->center[WHITE], this->center[YELLOW]->piece[(2+3*i)], (2+3*i), this->center[YELLOW]->piece[(2+3*i)]->getColor(YELLOW));
        this->changeCenter(this->center[GREEN], temp1[i], (6-3*i), temp1[i]->getColor(BLUE));
        this->changeCenter(this->center[YELLOW], temp2[i], (2+3*i), temp2[i]->getColor(WHITE));

    }

    temp1[0] = this->center[RED]->piece[0];
    temp1[1] = this->center[RED]->piece[1];
    temp1[2] = this->center[RED]->piece[2];
    temp2[0] = this->center[RED]->piece[3];

    this->center[RED]->piece[0] = this->center[RED]->piece[8];
    this->center[RED]->piece[1] = this->center[RED]->piece[7];
    this->center[RED]->piece[2] = this->center[RED]->piece[6];
    this->center[RED]->piece[3] = this->center[RED]->piece[5];
    this->center[RED]->piece[5] = temp2[0];
    this->center[RED]->piece[6] = temp1[2];
    this->center[RED]->piece[7] = temp1[1];
    this->center[RED]->piece[8] = temp1[0];


    temp1 = nullptr;
    temp2 = nullptr;

}

void Three::left(){

    Piece **temp = new Piece*[3];
    int color_temp;
    temp[0] = this->center[GREEN]->piece[8];
    temp[1] = this->center[GREEN]->piece[5];
    temp[2] = this->center[GREEN]->piece[2];
    // Capturando as cores de peças que sofrem de atraso na atualização da cor
    // Esse ponto faz com que, quanto formos atualizar a cor de duas das peças (a cada movimento),
    // As mesmas ja estejam apontando para os centros novos. Usamos o vetor de controle para não perder a referência

    color_temp = temp[0]->getColor(GREEN);

    for(int i = 0; i < 3; i++){

        this->changeCenter(this->center[GREEN], this->center[WHITE]->piece[(3*i)], (8-3*i), this->center[WHITE]->piece[(3*i)]->getColor(WHITE));
        this->changeCenter(this->center[WHITE], this->center[BLUE]->piece[(3*i)], (3*i), this->center[BLUE]->piece[(3*i)]->getColor(BLUE));
        this->changeCenter(this->center[BLUE], this->center[YELLOW]->piece[(3*i)], (3*i),this->center[YELLOW]->piece[(3*i)]->getColor(YELLOW));
        // this->changeCenter(this->center[WHITE], this->center[BLUE]->piece[(2+3*i)], (2+3*i), (i == 2 ? color_temp[1] : this->center[BLUE]->piece[(2+3*i)]->getColor(BLUE)));
        

    }
    
    this->changeCenter(this->center[YELLOW], temp[0], 0, color_temp);
    this->changeCenter(this->center[YELLOW], temp[1], 3, temp[1]->getColor(GREEN));
    this->changeCenter(this->center[YELLOW], temp[2], 6, temp[2]->getColor(GREEN));

    temp[0] = this->center[ORANGE]->piece[0];
    temp[1] = this->center[ORANGE]->piece[1];
    temp[2] = this->center[ORANGE]->piece[2];

    this->center[ORANGE]->piece[0] = this->center[ORANGE]->piece[6];
    this->center[ORANGE]->piece[1] = this->center[ORANGE]->piece[3];
    this->center[ORANGE]->piece[2] = temp[0];
    this->center[ORANGE]->piece[3] = this->center[ORANGE]->piece[7];
    this->center[ORANGE]->piece[7] = this->center[ORANGE]->piece[5];
    this->center[ORANGE]->piece[5] = temp[1];
    this->center[ORANGE]->piece[6] = this->center[ORANGE]->piece[8];
    this->center[ORANGE]->piece[8] = temp[2];
    temp = nullptr;    

}

void Three::left_line(){

    Piece **temp = new Piece*[3];
    int color_temp[2];
    temp[0] = this->center[BLUE]->piece[0];
    temp[1] = this->center[BLUE]->piece[3];
    temp[2] = this->center[BLUE]->piece[6];
    // Capturando as cores de peças que sofrem de atraso na atualização da cor
    // Esse ponto faz com que, quanto formos atualizar a cor de duas das peças (a cada movimento),
    // As mesmas ja estejam apontando para os centros novos. Usamos o vetor de controle para não perder a referência

    for(int i = 2; i >= 0; i--){

        this->changeCenter(this->center[BLUE], this->center[WHITE]->piece[(3*i)], (3*i), this->center[WHITE]->piece[(3*i)]->getColor(WHITE));
        this->changeCenter(this->center[WHITE], this->center[GREEN]->piece[(8-3*i)], (3*i), this->center[GREEN]->piece[(8-3*i)]->getColor(GREEN));
        this->changeCenter(this->center[GREEN], this->center[YELLOW]->piece[(3*i)], (8-3*i), this->center[YELLOW]->piece[(3*i)]->getColor(YELLOW));
        this->changeCenter(this->center[YELLOW], temp[i], (3*i), temp[i]->getColor(BLUE));

    }
    temp[0] = this->center[ORANGE]->piece[0];
    temp[1] = this->center[ORANGE]->piece[1];

    this->center[ORANGE]->piece[0] = this->center[ORANGE]->piece[2];
    this->center[ORANGE]->piece[1] = this->center[ORANGE]->piece[5];
    this->center[ORANGE]->piece[2] = this->center[ORANGE]->piece[8];
    this->center[ORANGE]->piece[5] = this->center[ORANGE]->piece[7];
    this->center[ORANGE]->piece[7] = this->center[ORANGE]->piece[3];
    this->center[ORANGE]->piece[3] = temp[1];
    this->center[ORANGE]->piece[8] = this->center[ORANGE]->piece[6];
    this->center[ORANGE]->piece[6] = temp[0];

    temp = nullptr;

}

void Three::left_two(){

    Piece **temp1 = new Piece*[3];
    Piece **temp2 = new Piece*[3];

    temp1[0] = this->center[BLUE]->piece[0];
    temp1[1] = this->center[BLUE]->piece[3];
    temp1[2] = this->center[BLUE]->piece[6];

    temp2[0] = this->center[WHITE]->piece[0];
    temp2[1] = this->center[WHITE]->piece[3];
    temp2[2] = this->center[WHITE]->piece[6];

    for(int i = 0; i < 3; i++){

        this->changeCenter(this->center[BLUE], this->center[GREEN]->piece[(8-3*i)], (3*i), this->center[GREEN]->piece[(8-3*i)]->getColor(GREEN));
        this->changeCenter(this->center[WHITE], this->center[YELLOW]->piece[(3*i)], (3*i), this->center[YELLOW]->piece[(3*i)]->getColor(YELLOW));
        this->changeCenter(this->center[GREEN], temp1[i], (8-3*i), temp1[i]->getColor(BLUE));
        this->changeCenter(this->center[YELLOW], temp2[i], (3*i), temp2[i]->getColor(WHITE));

    }

    temp1[0] = this->center[ORANGE]->piece[0];
    temp1[1] = this->center[ORANGE]->piece[1];
    temp1[2] = this->center[ORANGE]->piece[2];
    temp2[0] = this->center[ORANGE]->piece[3];

    this->center[ORANGE]->piece[0] = this->center[ORANGE]->piece[8];
    this->center[ORANGE]->piece[1] = this->center[ORANGE]->piece[7];
    this->center[ORANGE]->piece[2] = this->center[ORANGE]->piece[6];
    this->center[ORANGE]->piece[3] = this->center[ORANGE]->piece[5];
    this->center[ORANGE]->piece[5] = temp2[0];
    this->center[ORANGE]->piece[6] = temp1[2];
    this->center[ORANGE]->piece[7] = temp1[1];
    this->center[ORANGE]->piece[8] = temp1[0];


    temp1 = nullptr;
    temp2 = nullptr;

}

void Three::up(){

    Piece **temp = new Piece*[3];
    int color_temp;
    temp[0] = this->center[GREEN]->piece[0];
    temp[1] = this->center[GREEN]->piece[1];
    temp[2] = this->center[GREEN]->piece[2];

    for(int i = 2; i >= 0; i--){
        this->changeCenter(this->center[GREEN], this->center[ORANGE]->piece[i], i, this->center[ORANGE]->piece[i]->getColor(ORANGE));
        this->changeCenter(this->center[ORANGE], this->center[BLUE]->piece[i], i, this->center[BLUE]->piece[i]->getColor(BLUE));
        this->changeCenter(this->center[BLUE], this->center[RED]->piece[i], i, this->center[RED]->piece[i]->getColor(RED));
        this->changeCenter(this->center[RED], temp[i], i, temp[i]->getColor(GREEN));

    }

    temp[0] = this->center[YELLOW]->piece[0];
    temp[1] = this->center[YELLOW]->piece[1];
    temp[2] = this->center[YELLOW]->piece[2];

    this->center[YELLOW]->piece[0] = this->center[YELLOW]->piece[6];
    this->center[YELLOW]->piece[1] = this->center[YELLOW]->piece[3];
    this->center[YELLOW]->piece[2] = temp[0];
    this->center[YELLOW]->piece[3] = this->center[YELLOW]->piece[7];
    this->center[YELLOW]->piece[7] = this->center[YELLOW]->piece[5];
    this->center[YELLOW]->piece[5] = temp[1];
    this->center[YELLOW]->piece[6] = this->center[YELLOW]->piece[8];
    this->center[YELLOW]->piece[8] = temp[2];
    temp = nullptr;  

}

void Three::up_line(){

    Piece **temp = new Piece*[3];
    temp[0] = this->center[GREEN]->piece[0];
    temp[1] = this->center[GREEN]->piece[1];
    temp[2] = this->center[GREEN]->piece[2];

    for(int i = 0; i < 3; i++){

        this->changeCenter(this->center[GREEN], this->center[RED]->piece[i], i, this->center[RED]->piece[i]->getColor(RED));
        this->changeCenter(this->center[RED], this->center[BLUE]->piece[i], i, this->center[BLUE]->piece[i]->getColor(BLUE));
        this->changeCenter(this->center[BLUE], this->center[ORANGE]->piece[i], i, this->center[ORANGE]->piece[i]->getColor(ORANGE));
        this->changeCenter(this->center[ORANGE], temp[i], i, temp[i]->getColor(GREEN));

    }

    temp[0] = this->center[YELLOW]->piece[0];
    temp[1] = this->center[YELLOW]->piece[1];

    this->center[YELLOW]->piece[0] = this->center[YELLOW]->piece[2];
    this->center[YELLOW]->piece[1] = this->center[YELLOW]->piece[5];
    this->center[YELLOW]->piece[2] = this->center[YELLOW]->piece[8];
    this->center[YELLOW]->piece[5] = this->center[YELLOW]->piece[7];
    this->center[YELLOW]->piece[7] = this->center[YELLOW]->piece[3];
    this->center[YELLOW]->piece[3] = temp[1];
    this->center[YELLOW]->piece[8] = this->center[YELLOW]->piece[6];
    this->center[YELLOW]->piece[6] = temp[0];

    temp = nullptr;

}

void Three::up_two(){

    Piece **temp1 = new Piece*[3];
    Piece **temp2 = new Piece*[3];
    temp1[0] = this->center[BLUE]->piece[0];
    temp1[1] = this->center[BLUE]->piece[1];
    temp1[2] = this->center[BLUE]->piece[2];
    temp2[0] = this->center[ORANGE]->piece[0];
    temp2[1] = this->center[ORANGE]->piece[1];
    temp2[2] = this->center[ORANGE]->piece[2];

    for(int i = 0; i < 3; i++){

        this->changeCenter(this->center[BLUE], this->center[GREEN]->piece[i], i, this->center[GREEN]->piece[i]->getColor(GREEN));
        this->changeCenter(this->center[ORANGE], this->center[RED]->piece[i], i, this->center[RED]->piece[i]->getColor(RED));
        this->changeCenter(this->center[GREEN], temp1[i], i, temp1[i]->getColor(BLUE));
        this->changeCenter(this->center[RED], temp2[i], i, temp2[i]->getColor(ORANGE));

    }

    temp1[0] = this->center[YELLOW]->piece[0];
    temp1[1] = this->center[YELLOW]->piece[1];
    temp1[2] = this->center[YELLOW]->piece[2];
    temp2[0] = this->center[YELLOW]->piece[3];

    this->center[YELLOW]->piece[0] = this->center[YELLOW]->piece[8];
    this->center[YELLOW]->piece[1] = this->center[YELLOW]->piece[7];
    this->center[YELLOW]->piece[2] = this->center[YELLOW]->piece[6];
    this->center[YELLOW]->piece[3] = this->center[YELLOW]->piece[5];
    this->center[YELLOW]->piece[5] = temp2[0];
    this->center[YELLOW]->piece[6] = temp1[2];
    this->center[YELLOW]->piece[7] = temp1[1];
    this->center[YELLOW]->piece[8] = temp1[0];


    temp1 = nullptr;
    temp2 = nullptr;

}

void Three::down(){

    Piece **temp = new Piece*[3];
    temp[0] = this->center[GREEN]->piece[6];
    temp[1] = this->center[GREEN]->piece[7];
    temp[2] = this->center[GREEN]->piece[8];

    for(int i = 6; i < 9; i++){

        this->changeCenter(this->center[GREEN], this->center[RED]->piece[i], i, this->center[RED]->piece[i]->getColor(RED));
        this->changeCenter(this->center[RED], this->center[BLUE]->piece[i], i, this->center[BLUE]->piece[i]->getColor(BLUE));
        this->changeCenter(this->center[BLUE], this->center[ORANGE]->piece[i], i, this->center[ORANGE]->piece[i]->getColor(ORANGE));
        this->changeCenter(this->center[ORANGE], temp[i-6], i, temp[i-6]->getColor(GREEN));

    }

    temp[0] = this->center[WHITE]->piece[0];
    temp[1] = this->center[WHITE]->piece[1];
    temp[2] = this->center[WHITE]->piece[2];

    this->center[WHITE]->piece[0] = this->center[WHITE]->piece[6];
    this->center[WHITE]->piece[1] = this->center[WHITE]->piece[3];
    this->center[WHITE]->piece[2] = temp[0];
    this->center[WHITE]->piece[3] = this->center[WHITE]->piece[7];
    this->center[WHITE]->piece[7] = this->center[WHITE]->piece[5];
    this->center[WHITE]->piece[5] = temp[1];
    this->center[WHITE]->piece[6] = this->center[WHITE]->piece[8];
    this->center[WHITE]->piece[8] = temp[2];
    temp = nullptr;  

}

void Three::down_line(){

    Piece **temp = new Piece*[3];
    int color_temp;
    temp[0] = this->center[GREEN]->piece[6];
    temp[1] = this->center[GREEN]->piece[7];
    temp[2] = this->center[GREEN]->piece[8];

    for(int i = 8; i >= 6; i--){
        this->changeCenter(this->center[GREEN], this->center[ORANGE]->piece[i], i, this->center[ORANGE]->piece[i]->getColor(ORANGE));
        this->changeCenter(this->center[ORANGE], this->center[BLUE]->piece[i], i, this->center[BLUE]->piece[i]->getColor(BLUE));
        this->changeCenter(this->center[BLUE], this->center[RED]->piece[i], i, this->center[RED]->piece[i]->getColor(RED));
        this->changeCenter(this->center[RED], temp[i-6], i, temp[i-6]->getColor(GREEN));

    }

    temp[0] = this->center[WHITE]->piece[0];
    temp[1] = this->center[WHITE]->piece[1];

    this->center[WHITE]->piece[0] = this->center[WHITE]->piece[2];
    this->center[WHITE]->piece[1] = this->center[WHITE]->piece[5];
    this->center[WHITE]->piece[2] = this->center[WHITE]->piece[8];
    this->center[WHITE]->piece[5] = this->center[WHITE]->piece[7];
    this->center[WHITE]->piece[7] = this->center[WHITE]->piece[3];
    this->center[WHITE]->piece[3] = temp[1];
    this->center[WHITE]->piece[8] = this->center[WHITE]->piece[6];
    this->center[WHITE]->piece[6] = temp[0];

    temp = nullptr;
    
}

void Three::down_two(){

    Piece **temp1 = new Piece*[3];
    Piece **temp2 = new Piece*[3];
    temp1[0] = this->center[BLUE]->piece[6];
    temp1[1] = this->center[BLUE]->piece[7];
    temp1[2] = this->center[BLUE]->piece[8];
    temp2[0] = this->center[ORANGE]->piece[6];
    temp2[1] = this->center[ORANGE]->piece[7];
    temp2[2] = this->center[ORANGE]->piece[8];

    for(int i = 6; i < 9; i++){

        this->changeCenter(this->center[BLUE], this->center[GREEN]->piece[i], i, this->center[GREEN]->piece[i]->getColor(GREEN));
        this->changeCenter(this->center[ORANGE], this->center[RED]->piece[i], i, this->center[RED]->piece[i]->getColor(RED));
        this->changeCenter(this->center[GREEN], temp1[i-6], i, temp1[i-6]->getColor(BLUE));
        this->changeCenter(this->center[RED], temp2[i-6], i, temp2[i-6]->getColor(ORANGE));

    }

    temp1[0] = this->center[WHITE]->piece[0];
    temp1[1] = this->center[WHITE]->piece[1];
    temp1[2] = this->center[WHITE]->piece[2];
    temp2[0] = this->center[WHITE]->piece[3];

    this->center[WHITE]->piece[0] = this->center[WHITE]->piece[8];
    this->center[WHITE]->piece[1] = this->center[WHITE]->piece[7];
    this->center[WHITE]->piece[2] = this->center[WHITE]->piece[6];
    this->center[WHITE]->piece[3] = this->center[WHITE]->piece[5];
    this->center[WHITE]->piece[5] = temp2[0];
    this->center[WHITE]->piece[6] = temp1[2];
    this->center[WHITE]->piece[7] = temp1[1];
    this->center[WHITE]->piece[8] = temp1[0];


    temp1 = nullptr;
    temp2 = nullptr;

}

void Three::front(){

    Piece **temp = new Piece*[3];
    temp[0] = this->center[ORANGE]->piece[8];
    temp[1] = this->center[ORANGE]->piece[5];
    temp[2] = this->center[ORANGE]->piece[2];

    for(int i = 0; i < 3; i++){

        this->changeCenter(this->center[ORANGE], this->center[WHITE]->piece[(2-i)], (8-3*i), this->center[WHITE]->piece[(2-i)]->getColor(WHITE));
        this->changeCenter(this->center[WHITE], this->center[RED]->piece[(3*i)], (2-i), this->center[RED]->piece[(3*i)]->getColor(RED));
        this->changeCenter(this->center[RED], this->center[YELLOW]->piece[(6+i)], (3*i), this->center[YELLOW]->piece[(6+i)]->getColor(YELLOW));
        this->changeCenter(this->center[YELLOW], temp[i], (6+i), temp[i]->getColor(ORANGE));

    }

    temp[0] = this->center[BLUE]->piece[0];
    temp[1] = this->center[BLUE]->piece[1];
    temp[2] = this->center[BLUE]->piece[2];

    this->center[BLUE]->piece[0] = this->center[BLUE]->piece[6];
    this->center[BLUE]->piece[1] = this->center[BLUE]->piece[3];
    this->center[BLUE]->piece[2] = temp[0];
    this->center[BLUE]->piece[3] = this->center[BLUE]->piece[7];
    this->center[BLUE]->piece[7] = this->center[BLUE]->piece[5];
    this->center[BLUE]->piece[5] = temp[1];
    this->center[BLUE]->piece[6] = this->center[BLUE]->piece[8];
    this->center[BLUE]->piece[8] = temp[2];
    temp = nullptr;    


}

void Three::front_line(){

    Piece **temp = new Piece*[3];
    temp[0] = this->center[ORANGE]->piece[8];
    temp[1] = this->center[ORANGE]->piece[5];
    temp[2] = this->center[ORANGE]->piece[2];

    for(int i = 2; i >= 0; i--){

        this->changeCenter(this->center[ORANGE], this->center[YELLOW]->piece[(6+i)], (8-3*i), this->center[YELLOW]->piece[(6+i)]->getColor(YELLOW));
        this->changeCenter(this->center[YELLOW], this->center[RED]->piece[(3*i)], (6+i), this->center[RED]->piece[(3*i)]->getColor(RED));
        this->changeCenter(this->center[RED], this->center[WHITE]->piece[(2-i)], (3*i), this->center[WHITE]->piece[(2-i)]->getColor(WHITE));
        this->changeCenter(this->center[WHITE], temp[i], (2-i), temp[i]->getColor(ORANGE));

    }

    temp[0] = this->center[BLUE]->piece[0];
    temp[1] = this->center[BLUE]->piece[1];

    this->center[BLUE]->piece[0] = this->center[BLUE]->piece[2];
    this->center[BLUE]->piece[1] = this->center[BLUE]->piece[5];
    this->center[BLUE]->piece[2] = this->center[BLUE]->piece[8];
    this->center[BLUE]->piece[5] = this->center[BLUE]->piece[7];
    this->center[BLUE]->piece[7] = this->center[BLUE]->piece[3];
    this->center[BLUE]->piece[3] = temp[1];
    this->center[BLUE]->piece[8] = this->center[BLUE]->piece[6];
    this->center[BLUE]->piece[6] = temp[0];

    temp = nullptr;

}

void Three::front_two(){

    Piece **temp1 = new Piece*[3];
    Piece **temp2 = new Piece*[3];
    int color_temp;

    temp1[0] = this->center[RED]->piece[0];
    temp1[1] = this->center[RED]->piece[3];
    temp1[2] = this->center[RED]->piece[6];
    temp2[0] = this->center[WHITE]->piece[2];
    temp2[1] = this->center[WHITE]->piece[1];
    temp2[2] = this->center[WHITE]->piece[0];
    color_temp = this->center[YELLOW]->piece[8]->getColor(YELLOW);

    for(int i = 0; i < 3; i++){

        this->changeCenter(this->center[RED], this->center[ORANGE]->piece[(8-3*i)], (3*i), this->center[ORANGE]->piece[(8-3*i)]->getColor(ORANGE));
        this->changeCenter(this->center[WHITE], this->center[YELLOW]->piece[(6+i)], (2-i), (i == 2 ? color_temp : this->center[YELLOW]->piece[(6+i)]->getColor(YELLOW)));
        this->changeCenter(this->center[ORANGE], temp1[i], (8-3*i), temp1[i]->getColor(RED));
        this->changeCenter(this->center[YELLOW], temp2[i], (6+i), temp2[i]->getColor(WHITE));

    }   

    temp1[0] = this->center[BLUE]->piece[0];
    temp1[1] = this->center[BLUE]->piece[1];
    temp1[2] = this->center[BLUE]->piece[2];
    temp2[0] = this->center[BLUE]->piece[3];

    this->center[BLUE]->piece[0] = this->center[BLUE]->piece[8];
    this->center[BLUE]->piece[1] = this->center[BLUE]->piece[7];
    this->center[BLUE]->piece[2] = this->center[BLUE]->piece[6];
    this->center[BLUE]->piece[3] = this->center[BLUE]->piece[5];
    this->center[BLUE]->piece[5] = temp2[0];
    this->center[BLUE]->piece[6] = temp1[2];
    this->center[BLUE]->piece[7] = temp1[1];
    this->center[BLUE]->piece[8] = temp1[0];


    temp1 = nullptr;
    temp2 = nullptr;


}

void Three::back(){

    Piece **temp = new Piece*[3];
    temp[0] = this->center[RED]->piece[8];
    temp[1] = this->center[RED]->piece[5];
    temp[2] = this->center[RED]->piece[2];

    for(int i = 0; i < 3; i++){

        this->changeCenter(this->center[RED], this->center[WHITE]->piece[6+i], (8-3*i), this->center[WHITE]->piece[6+i]->getColor(WHITE));
        this->changeCenter(this->center[WHITE], this->center[ORANGE]->piece[(3*i)], (6+i), this->center[ORANGE]->piece[(3*i)]->getColor(ORANGE));
        this->changeCenter(this->center[ORANGE], this->center[YELLOW]->piece[(2-i)], (3*i), this->center[YELLOW]->piece[(2-i)]->getColor(YELLOW));
        this->changeCenter(this->center[YELLOW], temp[i], (2-i), temp[i]->getColor(RED));

    }

    temp[0] = this->center[GREEN]->piece[0];
    temp[1] = this->center[GREEN]->piece[1];
    temp[2] = this->center[GREEN]->piece[2];

    this->center[GREEN]->piece[0] = this->center[GREEN]->piece[6];
    this->center[GREEN]->piece[1] = this->center[GREEN]->piece[3];
    this->center[GREEN]->piece[2] = temp[0];
    this->center[GREEN]->piece[3] = this->center[GREEN]->piece[7];
    this->center[GREEN]->piece[7] = this->center[GREEN]->piece[5];
    this->center[GREEN]->piece[5] = temp[1];
    this->center[GREEN]->piece[6] = this->center[GREEN]->piece[8];
    this->center[GREEN]->piece[8] = temp[2];
    temp = nullptr;    


}

void Three::back_line(){

    Piece **temp = new Piece*[3];
    temp[0] = this->center[RED]->piece[8];
    temp[1] = this->center[RED]->piece[5];
    temp[2] = this->center[RED]->piece[2];

    for(int i = 2; i >= 0; i--){

        this->changeCenter(this->center[RED], this->center[YELLOW]->piece[(2-i)], (8-3*i), this->center[YELLOW]->piece[(2-i)]->getColor(YELLOW));
        this->changeCenter(this->center[YELLOW], this->center[ORANGE]->piece[(3*i)], (2-i), this->center[ORANGE]->piece[(3*i)]->getColor(ORANGE));
        this->changeCenter(this->center[ORANGE], this->center[WHITE]->piece[6+i], (3*i), this->center[WHITE]->piece[6+i]->getColor(WHITE));
        this->changeCenter(this->center[WHITE], temp[i], (6+i), temp[i]->getColor(RED));

    }

    temp[0] = this->center[GREEN]->piece[0];
    temp[1] = this->center[GREEN]->piece[1];

    this->center[GREEN]->piece[0] = this->center[GREEN]->piece[2];
    this->center[GREEN]->piece[1] = this->center[GREEN]->piece[5];
    this->center[GREEN]->piece[2] = this->center[GREEN]->piece[8];
    this->center[GREEN]->piece[5] = this->center[GREEN]->piece[7];
    this->center[GREEN]->piece[7] = this->center[GREEN]->piece[3];
    this->center[GREEN]->piece[3] = temp[1];
    this->center[GREEN]->piece[8] = this->center[GREEN]->piece[6];
    this->center[GREEN]->piece[6] = temp[0];

    temp = nullptr;

}

void Three::back_two(){

    Piece **temp1 = new Piece*[3];
    Piece **temp2 = new Piece*[3];
    int color_temp;

    temp1[0] = this->center[RED]->piece[2];
    temp1[1] = this->center[RED]->piece[5];
    temp1[2] = this->center[RED]->piece[8];
    temp2[0] = this->center[WHITE]->piece[8];
    temp2[1] = this->center[WHITE]->piece[7];
    temp2[2] = this->center[WHITE]->piece[6];
    color_temp = this->center[YELLOW]->piece[2]->getColor(YELLOW);

    for(int i = 0; i < 3; i++){

        this->changeCenter(this->center[RED], this->center[ORANGE]->piece[(6-3*i)], (2+3*i), this->center[ORANGE]->piece[(6-3*i)]->getColor(ORANGE));
        this->changeCenter(this->center[WHITE], this->center[YELLOW]->piece[(i)], (8-i), (i == 2 ? color_temp : this->center[YELLOW]->piece[(i)]->getColor(YELLOW)));
        this->changeCenter(this->center[ORANGE], temp1[i], (6-3*i), temp1[i]->getColor(RED));
        this->changeCenter(this->center[YELLOW], temp2[i], (i), temp2[i]->getColor(WHITE));

    }   

    temp1[0] = this->center[GREEN]->piece[0];
    temp1[1] = this->center[GREEN]->piece[1];
    temp1[2] = this->center[GREEN]->piece[2];
    temp2[0] = this->center[GREEN]->piece[3];

    this->center[GREEN]->piece[0] = this->center[GREEN]->piece[8];
    this->center[GREEN]->piece[1] = this->center[GREEN]->piece[7];
    this->center[GREEN]->piece[2] = this->center[GREEN]->piece[6];
    this->center[GREEN]->piece[3] = this->center[GREEN]->piece[5];
    this->center[GREEN]->piece[5] = temp2[0];
    this->center[GREEN]->piece[6] = temp1[2];
    this->center[GREEN]->piece[7] = temp1[1];
    this->center[GREEN]->piece[8] = temp1[0];


    temp1 = nullptr;
    temp2 = nullptr;

}

void Three::middle_vertical(){
    this->right_line();
    this->left();
}

void Three::middle_vertical_line(){
    this->right();
    this->left_line();
}

void Three::middle_vertical_two(){
    this->right_two();
    this->left_two();
}

void Three::middle_horizontal(){
    this->up_line();
    this->down();
}

void Three::middle_horizontal_line(){
    this->up();
    this->down_line();
}

void Three::middle_horizontal_two(){
    this->up_two();
    this->down_two();
}

std::string Three::move(int command[], int length){
    int tamanho = 0;
    std::string movements = "";
    
    for(int i = 0; i < length; i++){
        switch(command[i]){
            case 0: this->right(); movements += "R"; break;
            case 1: this->right_line(); movements += "R'"; break;
            case 2: this->right_two(); movements += "R2"; break;
            case 3: this->left(); movements += "L"; break;
            case 4: this->left_line(); movements += "L'"; break;
            case 5: this->left_two(); movements += "L2"; break;
            case 6: this->up(); movements += "U"; break;
            case 7: this->up_line(); movements += "U'"; break;
            case 8: this->up_two(); movements += "U2"; break;
            case 9: this->down(); movements += "D"; break;
            case 10: this->down_line(); movements += "D'"; break;
            case 11: this->down_two(); movements += "D2"; break;
            case 12: this->front(); movements += "F"; break;
            case 13: this->front_line(); movements += "F'"; break;
            case 14: this->front_two(); movements += "F2"; break;
            case 15: this->back(); movements += "B"; break;
            case 16: this->back_line(); movements += "B'"; break;
            case 17: this->back_two(); movements += "B2"; break;
            case 18: this->middle_vertical(); movements += "M"; break;
            case 19: this->middle_vertical_line(); movements += "M'"; break;
            case 20: this->middle_vertical_two(); movements += "M2"; break;
            case 21: this->middle_horizontal(); movements += "S"; break;
            case 22: this->middle_horizontal_line(); movements += "S'"; break;
            case 23: this->middle_horizontal_two(); movements += "S2"; break;
            default: break;
        }
        movements += " ";
    }

    return movements;
}

Piece **Three::getPiece(int color, bool type){

    Piece **array_return = new Piece*[4];
    int contador = 0;
    for(int i = 0; i < 6; i++){
        for(int j = (type == true ? 1 : 0); j < 9; j+= 2){
            if(j != 4 && this->center[i]->piece[j]->getColor(i) == color){
                array_return[contador] = this->center[i]->piece[j];
                contador++;
            }
        }
    }

    return array_return;

}

Piece **Three::getPiece(std::unordered_map<int, bool> *color, int length_color, bool type, int *except, int length){

    Piece **array_return;
    std::unordered_map<Piece*, bool>map_temp;
    std::vector<int> vector_temp;
    bool allowed;
    int contador = 0;

    for(int i = 0; i < 9; i++){
        if( i != 4){
            allowed = true;
            for(int j = 0; j < length; j++){
                if(i == except[j]){
                    allowed = false;
                    break;
                }
            }
            if(allowed){
                vector_temp.push_back(i);
            }
        }
    }

    for(int i = 0; i < 6; i++){
        for(const auto& j : vector_temp){
            for(int k = 0, contador = 0; k < length_color; k++){
                if(color->count(this->center[i]->piece[j]->color[0]) > 0 && color->count(this->center[i]->piece[j]->color[1]) > 0){
                    if(map_temp.count(this->center[i]->piece[j]) == 0){
                        map_temp[this->center[i]->piece[j]] = true;
                    }
                }
            }
        }
    }

    array_return = new Piece*[map_temp.size()];
    for(const auto& chave : map_temp){
        array_return[contador] = chave.first;
        contador++;
    }
    vector_temp.clear();
    map_temp.clear();

    return array_return;

}

bool Three::validate(){

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 9; j++){
            if(j != 4 && this->center[i]->piece[j]->getColor(i) != i){
                return false;
            }
        }
    }
    return true;

}

int Three::getRelativePosition(Piece *piece, int center){

    for(int i = 0; i < 9; i++){
        if(i != 4 && this->center[center]->piece[i] == piece){
            return i;
        }
    }
    return -1;

}

// Print

void Three::print(){ // Código escrito na mão pois a estrutura de dados tem tamanho fixo. Logo, não é necessário o uso de for

    // Printando amarelo
    
    for(int i = 0; i < 3; i++){
        print_space(false);
        for(int j = i*3; j < (i+1)*3; j++){
            if(j != 4){
                std::cout << this->center[YELLOW]->piece[j]->getColor(YELLOW) << " ";
            }else{
                std::cout << YELLOW << " ";
            }
            
        }
        print_space(true);
    }
    std::cout << std::endl;

    // Printando cores do meio (exceto o verde)
    for(int i = 0; i < 3; i++){

        for(int j = i*3; j < (i+1)*3; j++){
            if(j != 4){
                std::cout << this->center[ORANGE]->piece[j]->getColor(ORANGE) << " ";
            }else{
                std::cout << ORANGE << " ";
            }
            
        }
        std::cout << " ";
        for(int j = i*3; j < (i+1)*3; j++){
            if(j != 4){
                std::cout << this->center[BLUE]->piece[j]->getColor(BLUE) << " ";
            }else{
                std::cout << BLUE << " ";
            }
            
        }
        std::cout << " ";
        for(int j = i*3; j < (i+1)*3; j++){
            if(j != 4){
                std::cout << this->center[RED]->piece[j]->getColor(RED) << " ";
            }else{
                std::cout << RED << " ";
            }
            
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;

    for(int i = 0; i < 3; i++){
        print_space(false);
        for(int j = i*3; j < (i+1)*3; j++){
            if(j != 4){
                std::cout << this->center[WHITE]->piece[j]->getColor(WHITE) << " ";
            }else{
                std::cout << WHITE << " ";
            }
        }
        print_space(true);
    }
    std::cout << std::endl;

    for(int i = 2; i >= 0; i--){
        print_space(false);
        for(int j = ((i+1)*3)-1; j >= i*3; j--){
            if(j != 4){
                std::cout << this->center[GREEN]->piece[j]->getColor(GREEN) << " ";
            }else{
                std::cout << GREEN << " ";
            }
        }
        print_space(true);
    }

    // for(int i = 0; i < 3; i++){
    //     print_space(false);
    //     for(int j = i*3; j < (i+1)*3; j++){
    //         if(j != 4){
    //             std::cout << this->center[GREEN]->piece[j]->getColor(GREEN) << " ";
    //         }else{
    //             std::cout << GREEN << " ";
    //         }
            
    //     }
    //     print_space(true);
    // }
    std::cout << std::endl << std::endl;

}