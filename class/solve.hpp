#ifndef __SOLVE_H__
#define __SOLVE_H__

#include "three.hpp"

class Solve{

    private:
        
        short int ORANGE;
        short int BLUE;
        short int RED;
        short int GREEN;
        short int WHITE;
        short int YELLOW;

        Three *cube;
        std::string solve_algorithm;
        Piece **white_cross_on_yellow();
        void white_cross(Piece **white);
        void white_corner();
        void middle();
        void yellow_cross();
        void yellow_corner();
        void last_layer_permutation();
        bool done();
        void move(int command[], int length);

        // Funções criadas para facilitar as etapas e evitar checagens de centros repetitivas
        void move_right_up(int center);
        void move_right_down(int center);
        void move_right_two(int center);
        void move_left_up(int center);
        void move_left_down(int center);
        void move_left_two(int center);
        void move_front_right(int center);
        void move_front_left(int center);
        void move_front_two(int center);
        void move_up_right(int center);
        void move_up_left(int center);
        void move_up_two(int center);


    public:
        
        
        Solve();
        void shuffle();
        void shuffle(std::string encode);
        void print();

        void solve_using_layer_method();
        bool validate();

};

#endif