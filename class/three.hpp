#ifndef __TREE_H__
#define __TREE_H__

#include "center.hpp"
#include <iostream>
#include <unordered_map>




class Three{

    public:

        // Attributes
        const short int ORANGE = 0;
        const short int BLUE = 1;
        const short int RED = 2;
        const short int GREEN = 3;
        const short int WHITE = 4;
        const short int YELLOW = 5;
        Center **center;

        // Methods
        Three();
        void print();
        void changeCenter(Center *current_center, Piece *new_piece, int index, int color);

        void right();
        void right_line();
        void right_two();
        void left();
        void left_line();
        void left_two();
        void up();
        void up_line();
        void up_two();
        void down();
        void down_line();
        void down_two();
        void front();
        void front_line();
        void front_two();
        void back();
        void back_line();
        void back_two();
        void middle_vertical();
        void middle_vertical_line();
        void middle_vertical_two();
        void middle_horizontal();
        void middle_horizontal_line();
        void middle_horizontal_two();
        std::string move(int command[], int length);
        

        Piece **getPiece(int color, bool type);
        Piece **getPiece(std::unordered_map<int, bool> *color, int length_color, bool type, int *except, int length);
        int getRelativePosition(Piece *piece, int center); // Pega a posição da peça relativa ao centro passado
        bool validate();
        

};

#endif