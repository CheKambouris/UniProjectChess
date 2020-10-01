#include "Pieces.h"
#include <iostream>
#include <vector>

using namespace Chess;


std::vector<Piece *> createBoard()
{
    std::vector<Piece *> pieces = {
        new Rook    (uint64_t(1) << 0, Piece::Color::White),
        new Knight  (uint64_t(1) << 1, Piece::Color::White),
        new Bishop  (uint64_t(1) << 2, Piece::Color::White),
        new Queen   (uint64_t(1) << 3, Piece::Color::White),
        new King    (uint64_t(1) << 4, Piece::Color::White),
        new Bishop  (uint64_t(1) << 5, Piece::Color::White),
        new Knight  (uint64_t(1) << 6, Piece::Color::White),
        new Rook    (uint64_t(1) << 7, Piece::Color::White),

        new Pawn    (uint64_t(1) << 8, Piece::Color::White),
        new Pawn    (uint64_t(1) << 9, Piece::Color::White),
        new Pawn    (uint64_t(1) << 10, Piece::Color::White),
        new Pawn    (uint64_t(1) << 11, Piece::Color::White),
        new Pawn    (uint64_t(1) << 12, Piece::Color::White),
        new Pawn    (uint64_t(1) << 13, Piece::Color::White),
        new Pawn    (uint64_t(1) << 14, Piece::Color::White),
        new Pawn    (uint64_t(1) << 15, Piece::Color::White),


        new Pawn    (uint64_t(1) << 48, Piece::Color::Black),
        new Pawn    (uint64_t(1) << 49, Piece::Color::Black),
        new Pawn    (uint64_t(1) << 50, Piece::Color::Black),
        new Pawn    (uint64_t(1) << 51, Piece::Color::Black),
        new Pawn    (uint64_t(1) << 52, Piece::Color::Black),
        new Pawn    (uint64_t(1) << 53, Piece::Color::Black),
        new Pawn    (uint64_t(1) << 54, Piece::Color::Black),
        new Pawn    (uint64_t(1) << 55, Piece::Color::Black),

        new Rook    (uint64_t(1) << 56, Piece::Color::Black),
        new Knight  (uint64_t(1) << 57, Piece::Color::Black),
        new Bishop  (uint64_t(1) << 58, Piece::Color::Black),
        new King    (uint64_t(1) << 59, Piece::Color::Black),
        new Queen   (uint64_t(1) << 60, Piece::Color::Black),
        new Bishop  (uint64_t(1) << 61, Piece::Color::Black),
        new Knight  (uint64_t(1) << 62, Piece::Color::Black),
        new Rook    (uint64_t(1) << 63, Piece::Color::Black),
    };

    return pieces;
}


int main(int argc, char const *argv[])
{
    std::vector<Piece *> pieces = createBoard();

    std::cout << pieces[31]->get_piece_character() << std::endl;

    // free memory for pieces on the heap
    for (unsigned int i = 0; i < pieces.size(); i++) { delete pieces[i]; }

    return 0;
}
