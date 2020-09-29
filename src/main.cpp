#include "Pieces.h"
#include <iostream>

using namespace Chess;

int main(int argc, char const *argv[])
{
    std::cout << King(Bitboard(0), Piece::Color::White).get_piece_character() << std::endl;
    std::cout << Queen(Bitboard(0), Piece::Color::White).get_piece_character() << std::endl;
    std::cout << Pawn(Bitboard(0), Piece::Color::White).get_piece_character() << std::endl;
    std::cout << Bishop(Bitboard(0), Piece::Color::White).get_piece_character() << std::endl;
    std::cout << Rook(Bitboard(0), Piece::Color::White).get_piece_character() << std::endl;
    std::cout << Knight(Bitboard(0), Piece::Color::White).get_piece_character() << std::endl;
    
    return 0;
}
