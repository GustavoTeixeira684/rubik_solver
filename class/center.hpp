#ifndef __CENTER_H__
#define __CENTER_H__

#include "piece.hpp"


class Center{

    public:
        // Attributes
        short int color;
        Piece **piece; // Armazena as peças
        

        // Methods
        Center(short int color);
        ~Center();

};

#endif