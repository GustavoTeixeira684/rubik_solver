#ifndef __PIECE_H__
#define __PIECE_H__


class Piece{

    private:
        
        

    public:
        // Attributes
        bool type; // 0 para peça do canto e 1 para peça do meio
        short int length;
        int *center; // Armazena o numero do centro em que pertence (para efeitos de controle)
        int *color; // tem 2 cores para o meio e 3 cores para a ponta

        // Methods
        Piece(bool type);
        void setColor(int index, int color);
        void changeCenter(int color, int center);
        int getColor(int center);
        int *getOtherColor(int color);
        int getCenter(int color);
        int *getOtherCenter(int center);
        ~Piece();

};

#endif