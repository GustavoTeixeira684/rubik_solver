#include "solve.hpp"

std::string *split(const std::string text, const char delimiter, int *size){

    int contador = 0, quantidade = 0, i;
    std::string *retorno;
    for(i = 0; i < text.size(); i++){
        if(text[i] == ' '){
            quantidade++;
        }
    }

    retorno = new std::string[quantidade + 1];
    i = 0;
    for(contador = 0; contador <= quantidade; contador++){
        retorno[contador] = "";
        while(text[i] != '\0' && text[i] != ' '){
            retorno[contador] += text[i];
            i++;
        }
        if(text[i] == ' '){
            i++;
        }
    }
    *size = quantidade + 1;
    return retorno;

}

Solve::Solve(){
    this->cube = new Three();
    this->solve_algorithm = "";

    this->ORANGE = this->cube->ORANGE;
    this->BLUE = this->cube->BLUE;
    this->RED = this->cube->RED;
    this->GREEN = this->cube->GREEN;
    this->WHITE = this->cube->WHITE;
    this->YELLOW = this->cube->YELLOW;

}

void Solve::print(){
    this->cube->print();
}

void Solve::move(int command[], int length){

    this->solve_algorithm += this->cube->move(command, length);

}

void Solve::shuffle(){

    std::string movements;
    srand(time(NULL));
    int tamanho = (rand() % 21) + 10;
    int *encode = new int[tamanho];
    for(int i = 0; i < tamanho; i++){
        encode[i] = rand() % 18;
    }
    movements = this->cube->move(encode, tamanho);
    
    std::cout << "Shuffle Algorithm: " << movements << std::endl << std::endl;

}


void Solve::shuffle(std::string encode){
    // Não permite as movimentações do meio. Só é possível embaralhar com os movimentos básicos
    int size, *commands;
    std::string *commands_string = split(encode, ' ', &size);
    commands = new int[size];
    for(int i = 0; i < size; i++){
        if(commands_string[i] == "R"){
            commands[i] = 0;
        }else
        if(commands_string[i] == "R'"){
            commands[i] = 1;
        }else
        if(commands_string[i] == "R2"){
            commands[i] = 2;
        }else
        if(commands_string[i] == "L"){
            commands[i] = 3;
        }else
        if(commands_string[i] == "L'"){
            commands[i] = 4;
        }else
        if(commands_string[i] == "L2"){
            commands[i] = 5;
        }else
        if(commands_string[i] == "U"){
            commands[i] = 6;
        }else
        if(commands_string[i] == "U'"){
            commands[i] = 7;
        }else
        if(commands_string[i] == "U2"){
            commands[i] = 8;
        }else
        if(commands_string[i] == "D"){
            commands[i] = 9;
        }else
        if(commands_string[i] == "D'"){
            commands[i] = 10;
        }else
        if(commands_string[i] == "D2"){
            commands[i] = 11;
        }else
        if(commands_string[i] == "F"){
            commands[i] = 12;
        }else
        if(commands_string[i] == "F'"){
            commands[i] = 13;
        }else
        if(commands_string[i] == "F2"){
            commands[i] = 14;
        }else
        if(commands_string[i] == "B"){
            commands[i] = 15;
        }else
        if(commands_string[i] == "B'"){
            commands[i] = 16;
        }else
        if(commands_string[i] == "B2"){
            commands[i] = 17;
        }else{
            commands[i] = -1;
        }
    }
    
    this->cube->move(commands, size);
    std::cout << "Shuffle Algorithm: " << encode << std::endl << std::endl;

}

// Método para montar a cruz branca no amarelo
Piece** Solve::white_cross_on_yellow(){

    Piece **white = this->cube->getPiece(this->WHITE, true);
    int position, little_adjust[0], temp, center;

    for(int i = 0; i < 4; i++){

        if(white[i]->getCenter(this->WHITE) != this->YELLOW){
            center = white[i]->getCenter(this->WHITE);
            position = this->cube->getRelativePosition(white[i], center);
            
            // Inicia os movimentos
            if(position == 1){
                
                if(center == this->WHITE){

                    while(this->cube->center[this->YELLOW]->piece[7]->getColor(this->YELLOW) == this->WHITE){
                        little_adjust[0] = 6;
                        this->move(little_adjust,1);
                    }
                    little_adjust[0] = 14;
                    this->move(little_adjust,1);

                }else{
                    this->move_front_right(center);
                    switch(center){
                        case 0: temp = 7; break;
                        case 1: temp = 5; break;
                        case 2: temp = 1; break;
                        default: temp = 3; break;
                    }
                    if(this->cube->center[this->YELLOW]->piece[temp]->getColor(this->YELLOW) == this->WHITE){
                        little_adjust[0] = 7;
                        this->move(little_adjust,1);
                    }
                    this->move_right_up(center);
                }
                

            }else if(position == 3){

                if(center == this->WHITE){

                    while(this->cube->center[this->YELLOW]->piece[3]->getColor(this->YELLOW) == this->WHITE){
                        little_adjust[0] = 6;
                        this->move(little_adjust,1);
                    }
                    little_adjust[0] = 5;
                    this->move(little_adjust,1);

                }else{

                    switch(center){
                        case 0: temp = 1; break;
                        case 1: temp = 3; break;
                        case 2: temp = 7; break;
                        default: temp = 5; break;
                    }
                    while(this->cube->center[this->YELLOW]->piece[temp]->getColor(this->YELLOW) == this->WHITE){
                        little_adjust[0] = 6;
                        this->move(little_adjust,1);
                    }
                    this->move_left_up(center);
                }

            }else if(position == 5){
                
                if(center == this->WHITE){

                    while(this->cube->center[this->YELLOW]->piece[5]->getColor(this->YELLOW) == this->WHITE){
                        little_adjust[0] = 6;
                        this->move(little_adjust,1);
                    }
                    little_adjust[0] = 2;
                    this->move(little_adjust,1);

                }else{

                    switch(center){
                        case 0: temp = 7; break;
                        case 1: temp = 5; break;
                        case 2: temp = 1; break;
                        default: temp = 3; break;
                    }
                    while(this->cube->center[this->YELLOW]->piece[temp]->getColor(this->YELLOW) == this->WHITE){
                        little_adjust[0] = 6;
                        this->move(little_adjust,1);
                    }
                    this->move_right_up(center);
                }

            }else{ // Posição 7

                if(center == this->WHITE){

                    while(this->cube->center[this->YELLOW]->piece[1]->getColor(this->YELLOW) == this->WHITE){
                        little_adjust[0] = 6;
                        this->move(little_adjust,1);
                    }
                    little_adjust[0] = 17;
                    this->move(little_adjust,1);

                }else{
                    switch(center){
                        case 0: temp = 3; break;
                        case 1: temp = 7; break;
                        case 2: temp = 5; break;
                        default: temp = 1; break;
                    }
                    while(this->cube->center[this->YELLOW]->piece[temp]->getColor(this->YELLOW) == this->WHITE){
                        little_adjust[0] = 6;
                        this->move(little_adjust,1);
                    }
                    this->move_front_left(center);

                    switch(center){
                        case 0: temp = 7; break;
                        case 1: temp = 5; break;
                        case 2: temp = 1; break;
                        default: temp = 3; break;
                    }
                    while(this->cube->center[this->YELLOW]->piece[temp]->getColor(this->YELLOW) == this->WHITE){
                        little_adjust[0] = 7;
                        this->move(little_adjust,1);
                    }
                    this->move_right_up(center);
                }
                
            }

        }
        
    }

    return white;

}
 // Etapa 1 do método de camadas
void Solve::white_cross(Piece **white){

    for(int i = 0; i < 4; i++){

        int center = white[i]->getCenter(*white[i]->getOtherColor(this->WHITE));
        int color = *white[i]->getOtherColor(this->WHITE);

        if(center != color){
            int temp[1];
            if((center + 1) % 4 == color){
                temp[0] = 7;
            }else if((center + 3) % 4 == color){
                temp[0] = 6;
            }else{
                temp[0] = 8;
            }
            this->move(temp, 1);
        }
        
        this->move_front_two(color);

    }

}

// Etapa 2 do método de camadas
void Solve::white_corner(){

    Piece **white = this->cube->getPiece(this->WHITE, false);
    int *center, *color, little_adjust[0], temp;

    for(int i = 0; i < 4; i++){

        color = white[i]->getOtherColor(this->WHITE);
        if(white[i]->getCenter(this->WHITE) == this->WHITE){ // Se o branco está "encaixado"

            center = white[i]->getOtherCenter(this->WHITE);
            if(color[0] == center[0] && color[1] == center[1]){
                continue; // Ja está na posição certa
            }else{ // Tira da posição
                if(this->cube->center[center[0]]->piece[6] == white[i]){
                    this->move_left_up(center[0]);
                    this->move_up_right(center[0]);
                    this->move_left_down(center[0]);
                }else{
                    this->move_right_up(center[0]);
                    this->move_up_left(center[0]);
                    this->move_right_down(center[0]);
                }
                
            }
        }else{
            center = white[i]->getOtherCenter(white[i]->getCenter(this->WHITE));
            if(center[0] == this->WHITE || center[1] == this->WHITE){ // Se está na parte de baixo, mas com o branco para o "lado"
                temp = (center[0] == this->WHITE ? center[1] : center[0]);
                if(this->cube->center[temp]->piece[6] == white[i]){
                    this->move_left_up(temp);
                    this->move_up_right(temp);
                    this->move_left_down(temp);
                }else{
                    this->move_right_up(temp);
                    this->move_up_left(temp);
                    this->move_right_down(temp);
                }
                
            }else if(white[i]->getCenter(this->WHITE) == this->YELLOW){ // Se o branco está apontado para o amarelo

                temp = (this->cube->center[center[0]]->piece[0] == white[i] ? 6 : 8);
                while(this->cube->center[center[0]]->piece[temp]->getCenter(this->WHITE) != -1){
                    this->move_up_right(center[0]);
                    center = white[i]->getOtherCenter(white[i]->getCenter(this->WHITE));
                }//

                if(this->cube->center[center[0]]->piece[0] == white[i]){
                    this->move_left_up(center[0]);
                    this->move_up_two(center[0]);
                    this->move_left_down(center[0]);
                }else{
                    this->move_right_up(center[0]);
                    this->move_up_two(center[0]);
                    this->move_right_down(center[0]);
                }
            }
        }
        center = white[i]->getOtherCenter(white[i]->getCenter(this->WHITE)); // Atualizando os centros interessantes
        temp = (center[0] == this->YELLOW ? 1 : 0);

        if(center[temp] != color[temp]){
            int temp1[1];
            if((center[temp] + 1) % 4 == color[temp]){
                temp1[0] = 7;
            }else if((center[temp] + 3) % 4 == color[temp]){
                temp1[0] = 6;
            }else{
                temp1[0] = 8;
            }
            this->move(temp1, 1);
            center = white[i]->getOtherCenter(white[i]->getCenter(this->WHITE)); // Atualizando os centros interessantes
            temp = (center[0] == this->YELLOW ? 1 : 0);
        }

        

        if(this->cube->center[center[temp]]->piece[0] == white[i]){
            this->move_left_up(center[temp]);
            this->move_up_right(center[temp]);
            this->move_left_down(center[temp]);
        }else{
            this->move_right_up(center[temp]);
            this->move_up_left(center[temp]);
            this->move_right_down(center[temp]);
        }


    }


}

bool Solve::validate(){
    return this->cube->validate();
}

void Solve::middle(){

    int except[2] = {7}, current_center, current_color;
    std::unordered_map<int, bool> map_temp = {{0,1},{1,1},{2,1},{3,1}};
    Piece **middle = this->cube->getPiece(&map_temp, 4, true, except, 2);

    for(int i = 0; i < 4; i++){
        current_center = (middle[i]->center[0] == this->YELLOW ? middle[i]->center[1] : middle[i]->center[0]);
        if(this->cube->center[current_center]->piece[1] != middle[i]){
            if(this->cube->center[current_center]->piece[3] == middle[i]){
                this->move_left_up(current_center);
                this->move_up_right(current_center);
                this->move_left_down(current_center);
                this->move_up_left(current_center);
                this->move_front_right(current_center);
                this->move_up_left(current_center);
                this->move_front_left(current_center);
            }else{
                this->move_right_up(current_center);
                this->move_up_left(current_center);
                this->move_right_down(current_center);
                this->move_up_right(current_center);
                this->move_front_left(current_center);
                this->move_up_right(current_center);
                this->move_front_right(current_center);
            }
            current_center = (middle[i]->center[0] == this->YELLOW ? middle[i]->center[1] : middle[i]->center[0]);
        }

        current_color = (middle[i]->center[0] == this->YELLOW ? middle[i]->color[1] : middle[i]->color[0]);
        if(current_center != current_color){
            int temp1[1];
            if((current_center + 1) % 4 == current_color){
                temp1[0] = 7;
            }else if((current_center + 3) % 4 == current_color){
                temp1[0] = 6;
            }else{
                temp1[0] = 8;
            }
            this->move(temp1, 1);
        }

        if(*middle[i]->getOtherColor(current_color) == (current_color + 1) % 4){
            this->move_up_left(current_color); // Centro e cor alinhados. Portanto, não é necessário mais gastar recurso para atualizar a current_center
            this->move_right_up(current_color);
            this->move_up_left(current_color);
            this->move_right_down(current_color);
            this->move_up_right(current_color);
            this->move_front_left(current_color);
            this->move_up_right(current_color);
            this->move_front_right(current_color);
        }else{
            this->move_up_right(current_color);
            this->move_left_up(current_color);
            this->move_up_right(current_color);
            this->move_left_down(current_color);
            this->move_up_left(current_color);
            this->move_front_right(current_color);
            this->move_up_left(current_color);
            this->move_front_left(current_color);
        }

    }

    map_temp.clear();
    middle = nullptr;

}

void Solve::yellow_cross(){

    int contador = 0, index[4];
    for(int i = 1; i < 9; i += 2){
        if(this->cube->center[this->YELLOW]->piece[i]->getColor(this->YELLOW) == this->YELLOW){
            index[contador] = i;
            contador++;
        }
    }
    if(contador == 0){
        int movements[16] = {18,12,18,9,18,15,18,7,18,12,18,9,18,15,18,8}; // aqui
        this->move(movements, 16);
    }else if(contador == 2){
        Center *temp = this->cube->center[this->YELLOW]; // Apenas para sintaxe mais amigável
        if(index[0] + index[1] == 8){
            while(temp->piece[3]->getColor(this->YELLOW) != this->YELLOW || temp->piece[5]->getColor(this->YELLOW) != this->YELLOW){
                    this->move_front_right(this->YELLOW);
                  }
            
            int movements[6] = {12,0,6,1,7,13};
            this->move(movements, 6);

        }else{
            if(temp->piece[5]->getColor(this->YELLOW) == this->YELLOW){
                if(temp->piece[1]->getColor(this->YELLOW) == this->YELLOW){
                    this->move_front_left(this->YELLOW);
                }else{
                    this->move_front_two(this->YELLOW);
                }
            }else if(temp->piece[7]->getColor(this->YELLOW) == this->YELLOW){
                if(temp->piece[3]->getColor(this->YELLOW) == this->YELLOW){
                    this->move_front_right(this->YELLOW);
                }else{
                    this->move_front_two(this->YELLOW);
                }
                
            }

            int movements[6] = {12,6,0,7,1,13};
            this->move(movements, 6);
        }

    }

}

void Solve::yellow_corner(){

    int contador = 0, index[2];
    for(int i = 0; i < 9; i += 2){

        if(i != 4 && this->cube->center[this->YELLOW]->piece[i]->getColor(this->YELLOW) == this->YELLOW){
            if(contador < 2){ index[contador] = i;}
            contador++;
        }

    }
    if (contador == 0)
    {
        Center *center = this->cube->center[ORANGE];
        if(center->piece[0]->getColor(ORANGE) != YELLOW || center->piece[2]->getColor(ORANGE) != YELLOW){

            if(center->piece[0]->getColor(ORANGE) == YELLOW){
                this->move_front_right(YELLOW);
            }else if(center->piece[2]->getColor(ORANGE) == YELLOW){
                this->move_front_left(YELLOW);
            }else{
                if(this->cube->center[RED]->piece[0]->getColor(RED) != YELLOW){
                    this->move_front_right(YELLOW);
                }else{
                    this->move_front_two(YELLOW);
                }
            }

        }

        if(this->cube->center[RED]->piece[0]->getColor(RED) == YELLOW){ // outro

            int movement[11] = {0,6,1,6,0,7,1,6,0,8,1};
            this->move(movement,11);
            

        }else{ // Superman

            int movement[9] = {0,8,2,7,2,7,2,8,0};
            this->move(movement, 9);

        }
    }
    else if (contador == 1)
    {

        if(this->cube->center[this->YELLOW]->piece[6]->getColor(this->YELLOW) != this->YELLOW){
            
            if(this->cube->center[this->YELLOW]->piece[0]->getColor(this->YELLOW) == this->YELLOW){
                this->move_front_left(this->YELLOW);
            }else if(this->cube->center[this->YELLOW]->piece[8]->getColor(this->YELLOW) == this->YELLOW){
                this->move_front_right(this->YELLOW);
            }else{
                this->move_front_two(this->YELLOW);
            }
        }

        
        if(this->cube->center[this->BLUE]->piece[2]->getColor(this->BLUE) == this->YELLOW){
            int movement[7] = {0,6,1,6,0,8,1};
            this->move(movement, 7);
        }else{
            int movement[7] = {16,7,15,7,16,8,15};
            this->move(movement, 7);
        }
    }
    else
    {
        Center *center = this->cube->center[this->YELLOW]; // Para deixar a sintaxe mais fácil
        if(index[1] + index[0] == 8){ // Significa que estão em pontas opostas

            if(this->cube->center[this->BLUE]->piece[2]->getColor(BLUE) != YELLOW){
                if(this->cube->center[this->GREEN]->piece[2]->getColor(GREEN) == YELLOW){
                    this->move_front_two(YELLOW);
                }else if(this->cube->center[this->ORANGE]->piece[2]->getColor(ORANGE) == YELLOW){
                    this->move_front_left(YELLOW);
                }else{
                    this->move_front_right(YELLOW);
                }
            }

        int movement[8] = {0,15,3,16,1,15,4,16};
        this->move(movement, 8);

        }else{ // Significa que estão no mesmo lado

            if(index[0] + index[1] != 2){
                if(index[0] == 0){
                    this->move_front_right(YELLOW);
                }else if(index[0] == 2){
                    this->move_front_left(YELLOW);
                }else{
                    this->move_front_two(YELLOW);
                }
            }

            if(this->cube->center[BLUE]->piece[0]->getColor(BLUE) == YELLOW){
                int movement[9] = {2,9,1,8,0,10,1,8,1};
                this->move(movement, 9);
            }else{
                int movement[8] = {12,0,16,1,13,0,15,1};
                this->move(movement, 8);
            }
        

        }
        center = nullptr;
    }
}

bool Solve::done(){

    for(int i = 0; i < 4 ; i++){
        if(this->cube->center[i]->piece[0]->getColor(i) != this->cube->center[i]->piece[1]->getColor(i) || this->cube->center[i]->piece[0]->getColor(i) != this->cube->center[i]->piece[2]->getColor(i)){
            return false;
        }
    }
    return true;

}

void Solve::last_layer_permutation(){

    bool ready = true;
    bool almost = false;
    int contador = 0;
    for(int i = 0; i < 4; i++){
    
        if(this->cube->center[i]->piece[0]->getColor(i) != this->cube->center[i]->piece[2]->getColor(i)){
            ready = false; // indica estar pronto para finalizar ja
        }

    }

    if(contador < 4){ // Ainda não está pronto
        int color_ready;
        while(!ready){
            int movement[9] = {1,12,1,17,0,13,1,17,2};
            for(int i = 3; i >= 0; i--){

                if(this->cube->center[i]->piece[0]->getColor(i) == this->cube->center[i]->piece[2]->getColor(i)){
                    if(i != 3){
                        switch(i){
                            case 0: this->move_up_left(BLUE); break;
                            case 1: this->move_up_two(BLUE); break;
                            default: this->move_up_right(BLUE); break;
                        }
                    }
                    break;
                }

            }

            this->move(movement, 9);
            
            ready = true;
            for(int i = 0; i < 4; i++){
                if(this->cube->center[i]->piece[0]->getColor(i) != this->cube->center[i]->piece[2]->getColor(i)){
                    ready = false;
                }
            }

        }
        contador = 0;
        while(!this->done() && contador < 5){

            for(int i = 0; i < 4; i++){
                if(this->cube->center[i]->piece[0]->getColor(i) == this->cube->center[i]->piece[1]->getColor(i) && this->cube->center[i]->piece[0]->getColor(i) == this->cube->center[i]->piece[2]->getColor(i)){
                    if(i != 3){
                        switch(i){
                            case 0: this->move_up_left(BLUE); break;
                            case 1: this->move_up_two(BLUE); break;
                            default: this->move_up_right(BLUE); break;
                        }
                    }
                    break;
                }
            }

            if(this->cube->center[BLUE]->piece[1]->getColor(BLUE) == this->cube->center[RED]->piece[0]->getColor(RED)){
                int movement[7] = {14,7,18,14,19,7,14};
                this->move(movement, 7);
            }else{
                int movement[7] = {14,6,18,14,19,6,14};
                this->move(movement, 7);
            }

            contador++; // Garantir que não haverá loop infinito
        }

        if(this->cube->center[BLUE]->piece[1]->getColor(BLUE) != BLUE){
            switch(this->cube->center[BLUE]->piece[1]->getColor(BLUE)){
                case 0: this->move_up_left(BLUE); break;
                case 2: this->move_up_right(BLUE) ; break;
                default: this->move_up_two(BLUE); break;
            }
        }

    }

}

void Solve::solve_using_layer_method(){

    this->white_cross(this->white_cross_on_yellow());
    this->white_corner();
    this->middle();
    this->yellow_cross();
    this->yellow_corner();
    this->last_layer_permutation();

    std::cout << "Solve Algorithm: " << this->solve_algorithm << std::endl << std::endl;

}



// Funções criadas para facilitar as etapas e evitar checagens de centros repetitivas
void Solve::move_right_up(int center){

    int movement[1];

    switch(center){


        case 0: movement[0] = 12; break;
        case 1: movement[0] = 0; break;
        case 2: movement[0] = 15; break;
        case 3: movement[0] = 3; break;
        default: movement[0] = 0; break;

    }
    this->move(movement, 1);

}

void Solve::move_right_down(int center){

    int movement[1];

    switch(center){


        case 0: movement[0] = 13; break;
        case 1: movement[0] = 1; break;
        case 2: movement[0] = 16; break;
        case 3: movement[0] = 4; break;
        default: movement[0] = 1; break;

    }
    this->move(movement, 1);


}

void Solve::move_right_two(int center){

    int movement[1];

    switch(center){


        case 0: movement[0] = 14; break;
        case 1: movement[0] = 2; break;
        case 2: movement[0] = 17; break;
        case 3: movement[0] = 5; break;
        default: movement[0] = 2; break;

    }
    this->move(movement, 1);

}

void Solve::move_left_up(int center){

    int movement[1];

    switch(center){


        case 0: movement[0] = 16; break;
        case 1: movement[0] = 4; break;
        case 2: movement[0] = 13; break;
        case 3: movement[0] = 1; break;
        default: movement[0] = 4; break;

    }
    this->move(movement, 1);

}

void Solve::move_left_down(int center){

    int movement[1];

    switch(center){


        case 0: movement[0] = 15; break;
        case 1: movement[0] = 3; break;
        case 2: movement[0] = 12; break;
        case 3: movement[0] = 0; break;
        default: movement[0] = 3; break;

    }
    this->move(movement, 1);

}

void Solve::move_left_two(int center){

    int movement[1];

    switch(center){


        case 0: movement[0] = 17; break;
        case 1: movement[0] = 5; break;
        case 2: movement[0] = 14; break;
        case 3: movement[0] = 2; break;
        default: movement[0] = 5; break;

    }
    this->move(movement, 1);

}

void Solve::move_front_right(int center){

    int movement[1];

    switch(center){


        case 0: movement[0] = 3; break;
        case 1: movement[0] = 12; break;
        case 2: movement[0] = 0; break;
        case 3: movement[0] = 15; break;
        case 4: movement[0] = 9; break;
        default: movement[0] = 6; break;

    }
    this->move(movement, 1);


}

void Solve::move_front_left(int center){

    int movement[1];

    switch(center){


        case 0: movement[0] = 4; break;
        case 1: movement[0] = 13; break;
        case 2: movement[0] = 1; break;
        case 3: movement[0] = 16; break;
        case 4: movement[0] = 10; break;
        default: movement[0] = 7; break;

    }
    this->move(movement, 1);


}

void Solve::move_front_two(int center){

    int movement[1];

    switch(center){


        case 0: movement[0] = 5; break;
        case 1: movement[0] = 14; break;
        case 2: movement[0] = 2; break;
        case 3: movement[0] = 17; break;
        case 4: movement[0] = 11; break;
        default: movement[0] = 8; break;

    }
    this->move(movement, 1);


}

void Solve::move_up_right(int center){

    int movement[1];

    switch(center){


        case 4: movement[0] = 13; break;
        case 5: movement[0] = 16; break;
        default: movement[0] = 7; break;

    }
    this->move(movement, 1);


}

void Solve::move_up_left(int center){

    int movement[1];

    switch(center){


        case 4: movement[0] = 12; break;
        case 5: movement[0] = 15; break;
        default: movement[0] = 6; break;

    }
    this->move(movement, 1);


}

void Solve::move_up_two(int center){

    int movement[1];

    switch(center){


        case 4: movement[0] = 14; break;
        case 5: movement[0] = 17; break;
        default: movement[0] = 8; break;

    }
    this->move(movement, 1);


}