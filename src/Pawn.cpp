#include "Pawn.h"

using namespace Chess;

Pawn::Pawn(Bitboard location, Color color) : Piece(location, color) {}

Bitboard Pawn::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action> &history) const
{
    return allies;
}

char Pawn::get_piece_character() const
{
    return '\0';
}