#include "Rook.h"

using namespace Chess;

Rook::Rook(Bitboard location, Color color) : Piece(location, color) {}

Bitboard Rook::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action> &history) const
{
    return Bitboard(0);
}

char Rook::get_piece_character() const
{
    return 'R';
}