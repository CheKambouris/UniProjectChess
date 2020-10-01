#include "Pieces.h"
#include <iostream>
#include <vector>

using namespace Chess;

int main(int argc, char const *argv[])
{
    std::vector<Piece *> pieces;
    pieces.push_back(new King(Bitboard(1), Piece::Color::Black));

    std::cout << pieces[0]->get_piece_character() << std::endl;

    // free memory for pieces on the heap
    for (unsigned int i = 0; i < pieces.size(); i++) { delete pieces[i]; }

    return 0;
}
