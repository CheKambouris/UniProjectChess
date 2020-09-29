#include "Queen.h"

using namespace Chess;

Queen::Queen(Bitboard location, Color color) : Piece(location, color) {}

Bitboard Queen::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action> &history) const
{
    return Bitboard(0);
}

char Queen::get_piece_character() const
{
    return 'Q';
}