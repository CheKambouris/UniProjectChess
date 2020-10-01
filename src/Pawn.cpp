#include "Pawn.h"

using namespace Chess;

Pawn::Pawn(Bitboard location, Color color) : Piece(location, color) { }

Bitboard Pawn::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action> &history) const {
	Bitboard legal_moves;
	auto front = get_color() == Color::White? &Bitboard::north: &Bitboard::south;
	legal_moves += (get_location().*front)().inter(!allies);
	legal_moves += (get_location().*front)().west().inter(enemies);
	legal_moves += (get_location().*front)().east().inter(enemies);
	// Todo: En passant

	return legal_moves;
}

char Pawn::get_piece_character() const
{
	return '\0';
}