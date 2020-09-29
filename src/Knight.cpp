#include "Knight.h"

using namespace Chess;

Knight::Knight(Bitboard location, Color color) : Piece(location, color) {}

Bitboard Knight::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action> &history) const
{
    return Bitboard(0);
}

char Knight::get_piece_character() const
{
    return 'N';
}