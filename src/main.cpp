#include "Pieces.h"
#include <iostream>

using namespace Chess;

int main(int argc, char const *argv[])
{
    Pawn test_pawn = Pawn(Bitboard(0), Piece::Color::White);

    std::cout << test_pawn.get_piece_character() << std::endl;
    return 0;
}
