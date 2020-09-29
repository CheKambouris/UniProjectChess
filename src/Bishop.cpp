#include "Bishop.h"

using namespace Chess;

Bishop::Bishop(Bitboard location, Color color) : Piece(location, color) {}

Bitboard Bishop::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action> &history) const
{
    return Bitboard(0);
}

char Bishop::get_piece_character() const
{
    return 'B';
}