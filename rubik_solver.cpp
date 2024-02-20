#include <iostream>
#include <string.h>
#include <chrono>
#include "class/solve.hpp"

bool has_char(std::string text, char character){

    for(int i = 0; i < text.size(); i++){
        if(text[i] == character){
            return true;
        }
    }
    return false;

}

void print_help(){

    std::cout <<    "Rubik Solver, um programa de resolução de cubo mágico.\n";
    std::cout <<    "Com ele você pode colocar um \"algoritmo de embaralhamento\", apontando como seu cubo mágico está embaralhado. A partir disso, o programa exibirá uma forma de solução do mesmo.\n";
    std::cout <<    "Você pode passar por argumento o \"algoritmo de embaralhamento\" usando -s \"seu algoritmo\" ou não passar o parâmetro e deixar que o programa realiza um de forma aleatória, te apresentando o embaralhamento e a sua solução.\n";
    std::cout <<    "\n\n";
    std::cout <<    "Argumentos:";
    std::cout <<    "\n\n";
    std::cout <<    "\t-s : (shuffle) quando passado seque de um algoritmo de embaralhamento para ser resolvido Exemplo: rubik_solver -s \"R2 F' D2\"\n";
    std::cout <<    "\t-p : (print result) quando passado, o programa printa um esquema para demonstrar o embaralhamento\n";
    std::cout <<    "\t-t : (time) quando passado, o programa exibe quanto tempo levou para resolver por completo\n";
    std::cout <<    "\t--movement: Quando passado, o programa mostra o movimento que cada notação do algoritmo realiza(Ao colocar esse argumento o software irá exibir a explicação de movimentos ao invés de proceder normalmente)\n";
    std::cout <<    "\t--help: Trás informações sobre o programa (Ao colocar esse argumento o software irá exibir a explicação de ajuda ao invés de proceder normalmente)\n";
    std::cout <<    "Autor: Gustavo Teixeira\n\n";
}

void print_movement(){

    std::cout << "O algoritmo de cubo mágico utiliza alguns principios:\n";
    std::cout << "1 - A orientação padrão do programa é a cor azul para frente, branco para baixo e, consequentemente, amarelo para cima.\n";
    std::cout << "2 - O programa não realiza rotações no eixo do cubo mágico para sua solução. Logo, não é necessário faze-las enquanto estiver reproduzindo o algoritmo de resolução exibido pelo programa\n\n";
    
    std::cout << "Notações:\n";
    std::cout << "    \tR - Movimente a parte direita do cubo para cima\n";
    std::cout << "    \tR' - Movimente a parte direita do cubo para baixo\n";
    std::cout << "    \tR2 - Realize dois movimentos na parte direita do cubo\n";
    std::cout << "    \tL - Movimente a parte esquerda do cubo para baixo\n";
    std::cout << "    \tL' - Movimente a parte esquerda do cubo para cima\n";
    std::cout << "    \tL2 - Realize dois movimentos na parte esquerda do cubo\n";
    std::cout << "    \tU - Movimente a parte de cima do cubo para a direita\n";
    std::cout << "    \tU' - Movimente a parte de cima do cubo para a esquerda\n";
    std::cout << "    \tU2 - Realize dois movimentos na parte de cima do cubo\n";
    std::cout << "    \tD - Movimente a parte de baixo do cubo para a esquerda\n";
    std::cout << "    \tD' - Movimente a parte de baixo do cubo para a direita\n";
    std::cout << "    \tD2 - Realize dois movimentos na parte de baixo do cubo\n";
    std::cout << "    \tF - Movimente a parte da frente do cubo para a direita\n";
    std::cout << "    \tF' - Movimente a parte da frente do cubo para a esquerda\n";
    std::cout << "    \tF2 - Realize dois movimentos na parte da frente do cubo\n";
    std::cout << "    \tB - Movimente a parte de trás do cubo para a esquerda\n";
    std::cout << "    \tB' - Movimente a parte de trás do cubo para a direita\n";
    std::cout << "    \tB2 - Realize dois movimentos na parte de trás do cubo\n";
    std::cout << "    \tM - Notação para o movimento: R' L\n";
    std::cout << "    \tM' - Notação para o movimento R L'\n";
    std::cout << "OBS: Todas as notações de movimentos utilizadas nesse programas são notações oficiais de campeonatos de resolução de cubos mágicos.\n\n";

}

int main(int argc, char **argv){

    Solve *solve;
    bool has_shuffle = false, print_result = false, print_time = false, track = false;
    std::string shuffle_algorithm;
    if(argc > 1){
        int i = 1;
        while(i < argc){

            if(strcmp(argv[i], "--help") == 0){
                print_help();
                return 0;
            }else if(strcmp(argv[i], "--movement") == 0){
                print_movement();
                return 0;
            }else if(strcmp(argv[i], "-s") == 0){
                shuffle_algorithm = "";
                i++;
                while( i < argc && !has_char(argv[i], '-')){
                    if(shuffle_algorithm != ""){
                        shuffle_algorithm += " ";
                    }
                    shuffle_algorithm += argv[i];
                    i++;
                }
                has_shuffle = true;
            }else if(strcmp(argv[i], "-t") == 0){
                print_time = true;
                i++;
            }else if(strcmp(argv[i], "-p") == 0){
                print_result = true;
                i++;
            
            }else if(strcmp(argv[i], "-track") == 0){
                track = true;
            }else{
                std::cout << "argumento \"" << argv[i] << "\" não reconhecido. Por favor, digite \"--help\" para ver os argumentos possíveis" << std::endl;
                return -1;
            }
        }
    }
    solve = new Solve();
    if(has_shuffle){
        solve->shuffle(shuffle_algorithm);
    }else{
        solve->shuffle();
    }

    if(print_result){
        solve->print();
    }
    auto start = std::chrono::high_resolution_clock::now();
    solve->solve_using_layer_method();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    

    if(print_time){
        std::cout << "Tempo de execução: " << (long double)(duration.count() / 1e+6) << " segundos." << std::endl;
    }

    delete solve;
    


    return 0;
}