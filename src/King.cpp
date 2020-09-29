#include "King.h"

using namespace Chess;

King::King(Bitboard location, Color color) : Piece(location, color) {}

Bitboard King::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action> &history) const
{
    return Bitboard(0);
}

char King::get_piece_character() const
{
    return 'K';
}