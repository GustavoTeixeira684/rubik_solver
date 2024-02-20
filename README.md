
# Rubik Solver

Rubik Solver, um programa de resolução de cubo mágico.
Com ele você pode colocar um "algoritmo de embaralhamento", apontando como seu cubo mágico está embaralhado. A partir disso, o programa exibirá uma forma de solução do mesmo.
Você pode passar por argumento o "algoritmo de embaralhamento" usando -s "seu algoritmo" ou não passar o parâmetro e deixar que o programa realiza um de forma aleatória, te apresentando o embaralhamento e a sua solução.

## Argumentos:

    -s : (shuffle) quando passado seque de um algoritmo de embaralhamento para ser resolvido
    -p : (print result) quando passado, o programa printa um esquema para demonstrar a solução
    -t : (time) quando passado, o programa exibe quanto tempo levou para resolver por completo
    -track : quando passado, o programa exibe (imagens) de cada movimento realizado
    --movement: Quando passado, o programa mostra o movimento que cada notação do algoritmo realiza
    --help: Trás informações sobre o programa

O algoritmo de cubo mágico utiliza alguns principios:

 - 1 - A orientação padrão do programa é a cor azul para frente, branco para baixo e, consequentemente, amarelo para cima.

 - 2 - O programa não realiza rotações no eixo do cubo mágico para sua solução. Logo, não é necessário faze-las enquanto estiver reproduzindo o algoritmo de resolução exibido pelo programa


## Notações:
    R - Movimente a parte direita do cubo para cima
    R' - Movimente a parte direita do cubo para baixo
    R2 - Realize dois movimentos na parte direita do cubo
    L - Movimente a parte esquerda do cubo para baixo
    L' - Movimente a parte esquerda do cubo para cima
    L2 - Realize dois movimentos na parte esquerda do cubo
    U - Movimente a parte de cima do cubo para a direita
    U' - Movimente a parte de cima do cubo para a esquerda
    U2 - Realize dois movimentos na parte de cima do cubo
    D - Movimente a parte de baixo do cubo para a esquerda
    D' - Movimente a parte de baixo do cubo para a direita
    D2 - Realize dois movimentos na parte de baixo do cubo
    F - Movimente a parte da frente do cubo para a direita
    F' - Movimente a parte da frente do cubo para a esquerda
    F2 - Realize dois movimentos na parte da frente do cubo
    B - Movimente a parte de trás do cubo para a esquerda
    B' - Movimente a parte de trás do cubo para a direita
    B2 - Realize dois movimentos na parte de trás do cubo
    M - Notação para o movimento: R' L
    M' - Notação para o movimento R L'

***OBS: Todas as notações de movimentos utilizadas nesse programa são notações oficiais de campeonatos de resolução de cubos mágicos.***

## Instalação

### Requisitos
 - g++
 - git

Primeiro, clone este repositório:

    git clone git@github.com:GustavoTeixeira684/rubik_solver.git

Após isso, compile usando g++:

    g++ class/*.cpp rubik_solver.cpp -o rubik_solver

Com isso, seu resolvedor de cubo mágico estara compilado e pronto para executar!

Autor: Gustavo Teixeira

